#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 55;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n = 50;
int a, b, c, d;
char s[N][N];

void solve()
{
        cin >> a >> b >> c >> d;
        a--;
        int last;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        s[i][j] = 'A';
                }
                if(i % 2){
                        continue;
                }
                for(int j = 2; j <= n && (b || c || d); j += 2){
                        if(b){
                                s[i][j] = 'B';
                                b--;
                        }
                        else if(c){
                                s[i][j] = 'C';
                                c--;
                        }
                        else if(d){
                                s[i][j] = 'D';
                                d--;
                        }
                }
                if(!b && !c && !d){
                        last = i;
                        break;
                }
        }
        char g = s[last][2];
        for(int i = 1; i <= n; i++){
                s[last + 1][i] = 'A';
        }
        s[last + 1][2] = g;
        for(int i = last + 2; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        s[i][j] = g;
                }
                if(i % 2 == 0){
                        continue;
                }
                for(int j = 2; j <= n && a; j += 2){
                        s[i][j] = 'A';
                        a--;
                }
        }
        cout << 50 << " " << 50 << "\n";
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cout << s[i][j];
                }
                cout << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}