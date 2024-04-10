#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

int n;
int k;
char c[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i + 1 <= n && 1 <= k; i++){
        if(c[i] == '4' && c[i + 1] == '7'){
            if(i % 2 == 1){
                if(c[i + 2] == '7'){
                    if(k % 2)
                        c[i] = c[i + 1] = '4';
                    k = 1;
                }
                else
                    c[i] = c[i + 1] = '4';
                k--;
            }
            else{
                if(c[i - 1] == '4'){
                    if(k % 2)
                        c[i] = c[i + 1] = '7';
                    k = 1;
                }
                else
                    c[i] = c[i + 1] = '7';
                k--;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << c[i];
}