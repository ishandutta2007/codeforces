#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int inf = 1e9 + 1;

int n;
int x[N], y[N], c[N];
vector<int> A[3], B[3];
vector<pair<int, int>> aa[3], bb[3];

bool good_1(vector<int> &ord, int m)
{
        int x = ord[0], y = ord[1], z = ord[2];
        int last = A[x][m - 1];
        int i = lower_bound(A[y].begin(), A[y].end(), last + 1) - A[y].begin();
        if(i + m > A[y].size()){
                return false;
        }
        last = A[y][i + m - 1];

        i = lower_bound(A[z].begin(), A[z].end(), last + 1) - A[z].begin();
        if(i + m > A[z].size()){
                return false;
        }
        return true;
}

bool good_2(vector<int> &ord, int m)
{
        int x = ord[0], y = ord[1], z = ord[2];
        int last = A[x][m - 1];
        int last2 = -inf, j = 0;
        for(int i = 0; i < bb[y].size(); i++){
                if(::x[bb[y][i].se] <= last){
                        continue;
                }
                j += 1;
                if(j == m){
                        last2 = bb[y][i].fi;
                        break;
                }
        }
        if(j != m){
                return false;
        }
        j = 0;
        for(int i = 0; i < bb[z].size(); i++){
                if(::x[bb[z][i].se] <= last || bb[z][i].fi <= last2){
                        continue;
                }
                j += 1;
        }
        return j >= m;
}

bool good_3(vector<int> &ord, int m)
{
        int x = ord[0], y = ord[1], z = ord[2];
        int last = A[x][A[x].size() - m];
        int last2 = -inf, j = 0;
        for(int i = 0; i < bb[y].size(); i++){
                if(::x[bb[y][i].se] >= last){
                        continue;
                }
                j += 1;
                if(j == m){
                        last2 = bb[y][i].fi;
                        break;
                }
        }
        if(j != m){
                return false;
        }
        j = 0;
        for(int i = 0; i < bb[z].size(); i++){
                if(::x[bb[z][i].se] >= last || bb[z][i].fi <= last2){
                        continue;
                }
                j += 1;
        }
        return j >= m;
}

int solve(vector<int> ord)
{
        int l = 0, r = n / 3;
        while(l < r){
                int m = (l + r) / 2;
                if(good_1(ord, m + 1) || good_2(ord, m + 1) || good_3(ord, m + 1)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        return l;
}

int main()
{
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector<pair<int, int>> a, b;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i] >> c[i];
                c[i] -= 1;

                A[c[i]].push_back(x[i]);
                aa[c[i]].push_back({x[i], i});
                B[c[i]].push_back(y[i]);
                bb[c[i]].push_back({y[i], i});
        }
        for(int i = 0; i < 3; i++){
                sort(A[i].begin(), A[i].end());
                sort(aa[i].begin(), aa[i].end());
                sort(B[i].begin(), B[i].end());
                sort(bb[i].begin(), bb[i].end());
        }

        int res = 0;
        for(int it = 0; it < 2; it++){
                vector<int> v = {0, 1, 2};
                do{
                        res = max(res, solve(v));
                }while(next_permutation(v.begin(), v.end()));

                for(int i = 0; i < 3; i++){
                        swap(A[i], B[i]);
                        swap(aa[i], bb[i]);
                }
                for(int i = 1; i <= n; i++){
                        swap(x[i], y[i]);
                }
        }

        cout << 3 * res << "\n";
}