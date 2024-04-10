#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 8080;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int A, B, C;
                cin >> A >> B >> C;
                vector < int > res;
                if(B > 0){
                        for(int i = 0; i < B + 1; i++){
                                res.push_back(i % 2);
                        }
                }
                if(res.empty()){
                        if(A > 0){
                                res.push_back(0);
                        } else{
                                res.push_back(1);
                        }
                }
                for(int i = 0; i < res.size(); i++){
                        if(A > 0 && res[i] == 0){
                                vector < int > v;
                                for(int j = 0; j < i; j++) v.push_back(res[j]);
                                for(int j = 0; j < A; j++) v.push_back(0);
                                for(int j = i; j < res.size(); j++) v.push_back(res[j]);
                                res = v;
                                A = 0;
                        }
                        if(C > 0 && res[i] == 1){
                                vector < int > v;
                                for(int j = 0; j < i; j++) v.push_back(res[j]);
                                for(int j = 0; j < C; j++) v.push_back(1);
                                for(int j = i; j < res.size(); j++) v.push_back(res[j]);
                                res = v;
                                C = 0;
                        }
                }
                for(int x: res) cout << x;
                cout << "\n";
        }
}