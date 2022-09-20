#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;

int n;
int a[N];
string s[N];
set < int > A, B;

int tp(string s)
{
        if(s == "unlock"){
                return 2;
        } else if(s == "lock"){
                return 1;
        }
        return 3;
}

bool good(int x)
{
        if(a[x] == 2 && a[x + 1] == 3){
                return true;
        }
        return false;
}

void make()
{
        int id = 0;

        if(!A.empty()){
                        id = *(--A.end()) + 1;
        }
        id = *B.lower_bound(id) - 1;
        cout << s[id] << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
                a[i] = tp(s[i]);
        }
        for(int i = 1; i <= n; i++){
                if(good(i)){
                        A.insert(i);
                }
                if(a[i] != 3){
                        B.insert(i);
                }
        }
        s[0] = "blue";
        int q;
        cin >> q;
        B.insert(n + 1);
        make();
        for(int i = 1; i <= q; i++){
                int x;
                string t;
                cin >> x >> t;

                for(int j: {x, x - 1}){
                        if(good(j)){
                                A.erase(j);
                        }
                }
                if(a[x] != 3){
                        B.erase(x);
                }

                s[x] = t;
                a[x] = tp(t);

                if(a[x] != 3){
                        B.insert(x);
                }
                for(int j: {x, x - 1}){
                        if(good(j)){
                                A.insert(j);
                        }
                }

                make();
        }
}