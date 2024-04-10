#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 7070;

using namespace std;

int n;
int b[N];
int c[N];
long long a[N];

bool fuck(int x, int y)
{
        return a[x] > (a[x] & a[y]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < int > res;
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                for(int j = 1; j <= n; j++){
                        c[i] += fuck(i, j);
                }

                res.push_back(i);
        }

        vector < int > nv;

        while(res.size() > 1){
                int bitch = -1;

                for(int x: res){
                        if(c[x] == (int)res.size() - 1){
                                bitch = x;
                                break;
                        }
                }

                if(bitch == -1){
                        break;
                }

                nv.clear();
                for(int x: res){
                        if(x != bitch){
                                nv.push_back(x);
                                c[x] -= fuck(x, bitch);
                        }
                }
                res = nv;
        }
        if(res.size() == 1){
                res.clear();
        }

        long long sum = 0;
        for(int x: res){
                sum += b[x];
        }

        cout << sum << "\n";
}