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

using namespace std;

lli q;
map < pair < lli, lli >, lli > used;

int main()
{
    //freopen( "photo.in", "r", stdin );
    //freopen( "photo.out", "w", stdout );
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> q;
    for(int i = 1; i <= q; i++){
        lli x, y, t, w;
        cin >> t >> x >> y;
        if(t == 1){
            cin >> w;
            lli gx = 1,
                gy = 1;
            while((1ll << gx) <= x)
                gx++;
            while((1ll << gy) <= y)
                gy++;
            if(gx > gy){
                swap(gx, gy);
                swap(x, y);
            }
            while(gy > gx){
                gy--;
                used[{y, y / 2}] += w;
                y /= 2;
            }
            while(y != x){
                used[{x, x / 2}] += w;
                used[{y, y / 2}] += w;
                x /= 2;
                y /= 2;
            }
        }
        else{
            lli cnt = 0;
            lli gx = 1,
                gy = 1;
            while((1ll << gx) <= x)
                gx++;
            while((1ll << gy) <= y)
                gy++;
            if(gx > gy){
                swap(gx, gy);
                swap(x, y);
            }
            while(gy > gx){
                gy--;
                cnt += used[{y, y / 2}];
                y /= 2;
            }
            while(y != x){
                cnt += used[{x, x / 2}];
                cnt += used[{y, y / 2}];
                x /= 2;
                y /= 2;
            }
            cout << cnt << endl;
        }
    }
}