#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int get(int l, int r)
{
        cout << "? " << l << " " << r << endl;
        cin >> l;
        return l;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        int X = get(1, n);
        if(X == 1 || get(1, X) != X){
                int l = X + 1, r = n;
                while(l < r){
                        int m = (l + r) / 2;
                        if(get(1, m) == X){
                                r = m;
                        } else{
                                l = m + 1;
                        }
                }
                cout << "! " << l << endl;
        } else{
                int l = 1, r = X - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(get(m + 1, n) == X){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                cout << "! " << l << endl;
        }
}