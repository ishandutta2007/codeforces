#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303000;
const long long mod = 998244353;

using namespace std;

int n;
int s;
int a[N];
int b[N];
bool used[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);
        cin >> n >> s;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        queue < int > q;
        q.push(1);
        used[1] = 1;
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int i = x + 1; i <= n; i++){
                        if(!used[i] && a[i] && a[x]){
                                used[i] = true;
                                q.push(i);
                        }
                }
                for(int i = x - 1; i >= 1; i--){
                        if(!used[i] && b[i] && b[x]){
                                used[i] = true;
                                q.push(i);
                        }
                }
        }
        if(used[s]){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
}