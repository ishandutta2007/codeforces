#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 155;

using namespace std;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int a, b;
                cin >> a >> b;
                vector<int> used(a + b + 1, 0);
                for(int it = 0; it < 2; it++){
                        vector<int> c, d;
                        {
                                int x = a, y = b;
                                for(int i = 0; i < a + b; i++){
                                        if(i % 2 == 0){
                                                if(x){
                                                        c.push_back(0);
                                                        x--;
                                                } else{
                                                        c.push_back(1);
                                                        y--;
                                                }
                                        } else{
                                                if(y){
                                                        c.push_back(1);
                                                        y--;
                                                } else{
                                                        c.push_back(0);
                                                        x--;
                                                }
                                        }
                                }
                        }
                        {
                                int x = a, y = b;
                                for(int i = 0; i < a + b; i++){
                                        if(i % 2 == 1){
                                                if(x){
                                                        d.push_back(0);
                                                        x--;
                                                } else{
                                                        d.push_back(1);
                                                        y--;
                                                }
                                        } else{
                                                if(y){
                                                        d.push_back(1);
                                                        y--;
                                                } else{
                                                        d.push_back(0);
                                                        x--;
                                                }
                                        }
                                }
                        }
                        int A = 0, B = 0;
                        for(int i = 0; i < a + b; i++){
                                if(i % 2 == c[i]){
                                        A += 1;
                                }
                                if(i % 2 == d[i]){
                                        B += 1;
                                }
                        }
                        assert(B <= A && B % 2 == A % 2);
                        while(B <= A){
                                used[B] = 1;
                                B += 2;
                        }
                        swap(a, b);
                }
                vector<int> res;
                for(int i = 0; i <= a + b; i++){
                        if(used[i]){
                                res.push_back(i);
                        }
                }
                cout<< res.size() << "\n";
                for(int x: res){
                        cout << x << ' ';
                }
                cout << "\n";
        }
}