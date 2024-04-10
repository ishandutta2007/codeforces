#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int n,q,x,y,z;
int bsize;
ll add[710];
int sz[710];
pair<ll,int> blocks[710][710]; /// num/idx

int main()
{
    scanf("%d%d",&n,&q);
    bsize = (int)sqrt(n + 0.) + 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        blocks[i / bsize][sz[i / bsize]++] = make_pair(x, i);
    }
    for (int i = 0; i < bsize; ++i)
        sort(blocks[i], blocks[i] + sz[i]);

    while (q--) {
        scanf("%d%d",&z,&x);
        if (z == 1) {
            scanf("%d%d",&y,&z);
            --x; --y;
            int block_left = x / bsize;
            int block_right = y / bsize;
            for (int i = block_left + 1; i <= block_right - 1; ++i)
                add[i] += (ll)z;

            for (int i = 0; i < sz[block_left]; ++i) {
                if (blocks[block_left][i].second >= x && blocks[block_left][i].second <= y)
                    blocks[block_left][i].first += (ll)z;
            }
            sort(blocks[block_left], blocks[block_left] + sz[block_left]);

            if (block_left != block_right) {
                for (int i = 0; i < sz[block_right]; ++i) {
                    if (blocks[block_right][i].second >= x && blocks[block_right][i].second <= y)
                        blocks[block_right][i].first += (ll)z;
                }
                sort(blocks[block_right], blocks[block_right] + sz[block_right]);
            }
        } else {
            int lf = -1, rg = -1;
            for (int i = 0; i < bsize; ++i) {
                int L = 0, R = sz[i] - 1;
                while (L < R) {
                    int mid = (L + R) >> 1;
                    ll curnum = blocks[i][mid].first + add[i];
                    if (curnum > (ll)x)
                        R = mid - 1;
                    else if (curnum < (ll)x)
                        L = mid + 1;
                    else R = mid;
                }
                if (L == R && L >= 0 && L < sz[i] && blocks[i][L].first + add[i] == (ll)x) {
                    lf = blocks[i][L].second;
                    break;
                }
            }
            if (lf == -1) { printf("-1\n"); continue; }

            for (int i = bsize-1; i >= 0; --i) {
                int L = 0, R = sz[i] - 1;
                while (L < R) {
                    int mid = (L + R + 1) >> 1;
                    ll curnum = blocks[i][mid].first + add[i];
                    if (curnum > (ll)x)
                        R = mid - 1;
                    else if (curnum < (ll)x)
                        L = mid + 1;
                    else L = mid;
                }
                if (L == R && L >= 0 && L < sz[i] && blocks[i][L].first + add[i] == (ll)x) {
                    rg = blocks[i][L].second;
                    break;
                }
            }

            printf("%d\n", rg-lf);
        }
    }

    return 0;
}