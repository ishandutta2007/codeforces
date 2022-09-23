#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int hx[4][4];
int hy[4][4];
int x[4], y[4], a[4], b[4];
int nx[4], ny[4];

bool can()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int h = 0; h < 4; h++){
                for(int k = 0; k < 4; k++){
                    if(i == j || i == h || i == k || j == h || j == k || h == k)
                        continue;
                    bool bb = true;
                    if((nx[i] - nx[j]) * (nx[j] - nx[h]) != -1 * (ny[i] - ny[j]) * (ny[j] - ny[h]))
                        bb = false;
                    if((nx[j] - nx[h]) * (nx[h] - nx[k]) != -1 * (ny[j] - ny[h]) * (ny[h] - ny[k]))
                        bb = false;
                    if((nx[h] - nx[k]) * (nx[k] - nx[i]) != -1 * (ny[h] - ny[k]) * (ny[k] - ny[i]))
                        bb = false;
                    if((nx[k] - nx[i]) * (nx[i] - nx[j]) != -1 * (ny[k] - ny[i]) * (ny[i] - ny[j]))
                        bb = false;
                    int dist = (nx[i] - nx[j]) * (nx[i] - nx[j]) + (ny[i] - ny[j]) * (ny[i] - ny[j]);
                    if((nx[j] - nx[h]) * (nx[j] - nx[h]) + (ny[j] - ny[h]) * (ny[j] - ny[h]) != dist)
                        bb = false;
                    if((nx[h] - nx[k]) * (nx[h] - nx[k]) + (ny[h] - ny[k]) * (ny[h] - ny[k]) != dist)
                        bb = false;
                    if((nx[k] - nx[i]) * (nx[k] - nx[i]) + (ny[k] - ny[i]) * (ny[k] - ny[i]) != dist)
                        bb = false;
                    if((nx[i] == nx[h] && ny[i] == ny[h]))
                        bb = false;
                    if((nx[i] == nx[j] && ny[i] == ny[j]))
                        bb = false;
                    if((nx[i] == nx[k] && ny[i] == ny[k]))
                        bb = false;
                    if((nx[j] == nx[h] && ny[j] == ny[h]))
                        bb = false;
                    if((nx[k] == nx[h] && ny[k] == ny[h]))
                        bb = false;
                    if((nx[j] == nx[k] && ny[j] == ny[k]))
                        bb = false;
                    if(bb){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int solve()
{
    int ans = 1e9;
    for(int i = 0; i < 4; i++){
        nx[0] = a[0] + hx[0][i];
        ny[0] = b[0] + hy[0][i];
        for(int j = 0; j < 4; j++){
            nx[1] = a[1] + hx[1][j];
            ny[1] = b[1] + hy[1][j];
            for(int h = 0; h < 4; h++){
                nx[2] = a[2] + hx[2][h];
                ny[2] = b[2] + hy[2][h];
                for(int k = 0; k < 4; k++){
                    nx[3] = a[3] + hx[3][k];
                    ny[3] = b[3] + hy[3][k];
                    if(can()){
                        ans = min(ans, i + j + h + k);
                        return ans;
                    }
                }
            }
        }
    }
    if(ans == 1e9)
        ans = -1;
    return ans;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            cin >> x[j] >> y[j] >> a[j] >> b[j];
            int xx = x[j] - a[j],
                yy = y[j] - b[j];
            hx[j][0] = xx;
            hx[j][1] = -yy;
            hx[j][2] = -xx;
            hx[j][3] = yy;
            hy[j][0] = yy;
            hy[j][1] = xx;
            hy[j][2] = -yy;
            hy[j][3] = -xx;
        }
        cout << solve() << endl;
    }
}