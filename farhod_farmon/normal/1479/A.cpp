#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;

using namespace std;

int get(int x)
{
        cout << "? " << x << endl;
        cin >> x;
        return x;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        int l = 1, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(get(m) < get(m + 1)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << "! " << l << endl;
}