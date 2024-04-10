#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
long long res, C;
set < int > A, B;
set < pair < int, int > > S, T;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        long long sum = 0;
        for(int i = 1; i <= n; i++){
                int t, x;
                cin >> t >> x;
                sum += x;
                if(t == 0){
                        if(x > 0){
                                A.insert(x);
                                T.insert({x, 0});
                        } else{
                                x = -x;
                                A.erase(x);
                                if(S.find({x, 0}) != S.end()){
                                        res -= x;
                                        S.erase({x, 0});
                                } else{
                                        T.erase({x, 0});
                                }
                        }
                } else{
                        if(x > 0){
                                B.insert(x);
                                T.insert({x, 1});
                        } else{
                                x = -x;
                                B.erase(x);
                                if(S.find({x, 1}) != S.end()){
                                        res -= x;
                                        C -= 1;
                                        S.erase({x, 1});
                                } else{
                                        T.erase({x, 1});
                                }
                        }
                }
                while(S.size() > B.size()){
                        auto p = *S.begin();
                        S.erase(p);
                        T.insert(p);
                        res -= p.fi;
                        C -= p.se;
                }
                while(S.size() < B.size()){
                        auto p = *(--T.end());
                        T.erase(p);
                        S.insert(p);
                        res += p.fi;
                        C += p.se;
                }
                while(!S.empty() && !T.empty() && S.begin()->fi < (--T.end())->fi){
                        auto p = *S.begin();
                        auto q = *(--T.end());
                        S.erase(p);
                        T.erase(q);
                        S.insert(q);
                        T.insert(p);
                        res += q.fi - p.fi;
                        C += q.se - p.se;
                }
                long long cur = sum + res;
                if(C == B.size() && C > 0){
                        cur -= *B.begin();
                        if(!A.empty()){
                                cur += *(--A.end());
                        }
                }
                cout << cur << "\n";
        }
}