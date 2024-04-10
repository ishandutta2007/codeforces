#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    for(cin >> _; _; _ -= 1){
        LL d, k;
        cin >> d >> k;
        vector<LL> v;
        for(LL i = 0, j = d / k * k; i <= d; i += k){
            while(i * i + j * j > d * d) j -= k;
            v.push_back(j / k + 1);
        }
        //for(LL x : v) cout << x << " "; cout << "\n";
        reverse(v.begin(), v.end());
        deque<int> dq;
        LL L = -1;
        for(LL x : v){
            if(L == -1) for(LL i = 1; i <= x; i += 1) dq.push_back((x - i) & 1);
            else{
                int z = dq.front();
                dq.pop_front();
                if(dq.empty()) dq.push_back(z ^ 1);
                else{
                    if(z == 1 and dq.back() == 1) dq.push_back(0);
                    else dq.push_back(z);
                }
                if(dq.back() == 0 and ((x - L) & 1) == 1) dq.back() = 1;
                for(int i = L + 1; i <= x; i += 1) dq.push_back((x - i) & 1);
            }
            L = x;
            if(d <= 0){
                for(int x : dq) cout << x << " ";
                cout << '\n';
            }
        }
        cout << (dq.front() ? "Ashish\n" : "Utkarsh\n");
    }
    return 0;
}