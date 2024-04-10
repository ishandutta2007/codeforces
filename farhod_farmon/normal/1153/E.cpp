#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int ask(int x1, int y1, int x2, int y2)
{
        int k;
        cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        cin >> k;
        return k;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > a, b;
        for(int i = 1; i <= n; i++){
                a.push_back(ask(i, 1, i, n) % 2);
                b.push_back(ask(1, i, n, i) % 2);
                if(a.back() == 0){
                        a.pop_back();
                } else{
                        a.back() = i;
                }
                if(b.back() == 0){
                        b.pop_back();
                } else{
                        b.back() = i;
                }
        }

        if(!a.empty() && !b.empty()){
                int x1 = a[0], x2 = a[1], y1 = b[0], y2 = b[1];
                if(ask(x1, y1, x1, y1) % 2 == 0){
                        swap(y1, y2);
                }
                cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                return 0;
        } else if(!a.empty()){
                int x1 = a[0], x2 = a[1];
                int l = 1, r = n;
                while(l < r){
                        int m = (l + r) / 2;
                        if(ask(x1, 1, x1, m) % 2){
                                r = m;
                        } else{
                                l = m + 1;
                        }
                }
                cout << "! " << x1 << " " << l << " " << x2 << " " << l << endl;
                return 0;
        } else{
                int y1 = b[0], y2 = b[1];
                int l = 1, r = n;
                while(l < r){
                        int m = (l + r) / 2;
                        if(ask(1, y1, m, y1) % 2){
                                r = m;
                        } else{
                                l = m + 1;
                        }
                }
                cout << "! " << l << " " << y1 << " " << l << " " << y2 << endl;
                return 0;
        }
}