#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
bool used[Q];
vector < int > q[Q];

bool can(int x)
{
        for(int y: q[x]){
                if(used[y]){
                        return false;
                }
        }
        return true;
}

void solve()
{
        vector < int > v;
        for(int i = 2; i < Q; i++){
                if(!q[i].empty()){
                        continue;
                }
                v.push_back(i);
                for(int j = i; j < Q; j += i){
                        q[j].push_back(i);
                }
        }
        cin >> n;
        int last = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                if(can(a[i])){
                        for(int y: q[a[i]]){
                                used[y] = 1;
                        }
                        last = i;
                }
                else{
                        break;
                }
        }
        for(int i = 1; i <= last; i++){
                cout << a[i] << " ";
        }
        if(last < n){
                for(int i = a[last + 1] + 1; i < Q; i++){
                        if(can(i)){
                                cout << i << " ";
                                for(int y: q[i]){
                                        used[y] = 1;
                                }
                                break;
                        }
                }
        }
        for(int i = last + 2, j = 2; i <= n; i++){
                while(!can(j)){
                        j++;
                }
                cout << j << " ";
                for(int y: q[j]){
                        used[y] = 1;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}