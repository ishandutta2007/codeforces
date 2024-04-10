#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) x.size())
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x, y) cerr << #x << " is " << x << ", " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
typedef long long lint;
typedef pair<lint, lint> ii;


void terntovec(int mask, int n, vector<int> &res){
	for(int i = 0;i < n;i++){
		res.push_back(mask%3 - 1);
		mask /= 3;
	}
}

void conv(vector<int> arr, vector<ii> &res){
	int n = sz(arr);

	int T = 1;
	for(int i = 1;i <= n;i++) T *= 3;

	for(int mask = 0;mask < T;mask++){
		int M = mask;

		lint S = 0; lint cnt = 0;
		for(int i = 0;i < n;i++){
			int t = M%3 - 1;
			M /= 3;
			S += t * arr[i];
			cnt += t;
		}

		res.push_back(ii(S*100LL+cnt, mask));
	}

	return;
}

vector<int> findtwosets(vector<int> arr){
	vector<int> brr;
	while((int) arr.size() > sz(brr)){
		brr.push_back(arr.back());
		arr.pop_back();
	}

	reverse(all(brr));

	vector<ii> A; conv(arr, A);
	vector<ii> B; conv(brr, B);


	sort(all(A));
	sort(all(B));

	auto it = B.begin();
	for(auto a : A){
		while(it != B.end() and it->first < a.first) it++;
		if(it->first == a.first and it != B.end()){
			auto b = it->second;

			vector<int> av;
			terntovec(a.second, sz(arr), av);

			vector<int> bv;
			terntovec(b, sz(brr), bv);

			vector<int> res;
			for(int x : av) res.push_back(x);
			for(int x : bv) res.push_back(-x);

			int k = 0;
			for(int x : res) k += abs(x);
			if(k == 0) continue;

			return res;
		}
	}

	return {};
}
bool cmp(int a, int b) {
    return a%2 < b%2;
}
int main() {
    int n; cin>>n;
    vector<int> a(n);
    bool all_odd = true;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(a[i]%2==0) {
            all_odd = false;
        }
    }
    if(n==2) {
        if(a[0]==a[1]) {
            cout << "YES\n";
            cout << 0 << " " << a[0] << "\n";
        } else {
            cout << "NO\n";
        }
        return 0;
    }
    if(all_odd) {
        vector<int> b;
        for(int i=0; i<26 && i<n; i++) {
            b.push_back(a[i]);
        }
        vector<int> z = findtwosets(b);
        if(z.size()==0) {
            cout << "NO\n";
            return 0;
        }
        assert(z.size() == b.size());
        vector<int> a1;
        vector<int> a2;
        vector<int> a3;
        for(int i=0; i<z.size(); i++) {
            if(z[i]==1) {
                a1.push_back(a[i]);
            } else if(z[i]==-1) {
                a2.push_back(a[i]);
            } else {
                a3.push_back(a[i]);
            }
        }
        vector<int> ans;
        ans.push_back(0);
        for(int i=0; i<a1.size(); i++) {
            ans.push_back(a1[i]-ans.back());
            ans.push_back(a2[i]-ans.back());
        }
        assert(ans.back()==0);
        ans.pop_back();
        for(int i=26; i<n; i++) {
            ans.push_back(a[i]);
        }
        cout << "YES\n";
        for(int i: ans) {
            cout << i << " ";
        }
        for(int i: a3) {
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
    sort(a.begin(), a.end(), cmp);
    assert(a[0]%2==0);
    if(a.back()%2==1 && a[a.size()-2]%2==1) {
        reverse(a.begin()+1, a.end());
    }

    if((a[0]+a[1]+a[2])%2 == 0) {
        int w = (a[0]+a[1]-a[2])/2;
        int x = (a[0]-a[1]+a[2])/2;
        int y = (-a[0]+a[1]+a[2])/2;
        cout << "YES\n";
        cout << w << " " << x << " " << y << " ";
        for(int i=3; i<a.size(); i++) {
            cout << a[i]-w << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

}