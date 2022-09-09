#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
const double Phi = (sqrt(5) - 1) / 2;
vector<pair<int, int>> v;
double xL = 0, xR = maxn, yL = 0, yR = maxn;
int ax = 1, ay = 1, ans = maxn;
int g(int x, int y){
    int r = 0;
    for(auto& [p, q] : v){
        if(x <= p and y <= q) r = max(r, max(p - x, q - y));
        else if(x >= p and y >= q) r = max(r, max(x - p, y - q));
        else r = max(abs(x - p) + abs(y - q), r);
    }
    return r;
}
double f(double x, double y){
    double r = 0;
    for(auto& [p, q] : v){
        if(x <= p and y <= q) r = max(r, max(p - x, q - y));
        else if(x >= p and y >= q) r = max(r, max(x - p, y - q));
        else r = max(abs(x - p) + abs(y - q), r);
    }
    return r;
}
double f(double x){
    yL = 0, yR = maxn;
    double ymL = Phi * yL + (1 - Phi) * yR;
    double ymR = Phi * yR + (1 - Phi) * yL;
    double fmL = f(x, ymL), fmR = f(x, ymR);
    while(yR - yL > .5){
	    if(fmL > fmR){
			yL = ymL;
			ymL = ymR;
			fmL = fmR;
			fmR = f(x, ymR = Phi * yR + (1 - Phi) * yL);
		}
		else{
			yR = ymR;
			ymR = ymL;
			fmR = fmL;
			fmL = f(x, ymL = Phi * yL + (1 - Phi) * yR);	
		}
    }
    return fmL;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i += 1){
        string s;
        cin >> s;
        for(char c : s) (c == 'B' ? v[i].first : v[i].second) += 1;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    n = v.size();
	double xmL = Phi * xL + (1 - Phi) * xR;
	double xmR = Phi * xR + (1 - Phi) * xL;
    double fmL = f(xmL), fmR = f(xmR);
    while(xR - xL > .5){
	    if(fmL > fmR){
			xL = xmL;
			xmL = xmR;
			fmL = fmR;
			fmR = f(xmR = Phi * xR + (1 - Phi) * xL);
		}
		else{
			xR = xmR;
			xmR = xmL;
			fmR = fmL;
			fmL = f(xmL = Phi * xL + (1 - Phi) * xR);	
		}
    }
    //cout << xL << " " << xR << " " << yL << " " << yR << "\n";
    for(int i = xL - 2; i <= xR + 2; i += 1)
        for(int j = yL - 2; j <= yR + 2; j += 1)
            if(i >= 0 and j >= 0 and i + j >= 1){
                int pans = g(i, j);
                if(pans <= ans){
                    ans = pans;
                    ax = i;
                    ay = j;
                }
            }
    cout << ans << "\n";
    for(int i = 0; i < ax; i += 1) cout << 'B';
    for(int i = 0; i < ay; i += 1) cout << 'N';
    return 0;
}