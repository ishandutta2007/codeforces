#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

struct mv {
    int t, i, sz;
};

int n, m, a[110][110], sum, sum2, menor_i[110], menor_j[110];
vector<mv> ans, ans2;

void print(int quant, int idx) {
    vector <mv> v;
    if(idx == 1) v = ans;
    else v = ans2;

    printf("%d\n", quant);
    for(mv x : v) {
        for(int j=0; j<x.sz; j++) {
            if(x.t == 0) printf("row ");
            else printf("col ");

            printf("%d\n", x.i + 1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        menor_i[i] = 9999999;
    for(int j=0; j<m; j++)
        menor_j[j] = 9999999;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d",&a[i][j]);
            sum += a[i][j];
            menor_i[i] = min(menor_i[i], a[i][j]);
            menor_j[j] = min(menor_j[j], a[i][j]);
        }
    }

    sum2 = sum;

    int mv1 = 0, mv2 = 0;

    for(int i=0; i<n; i++) {
        mv1 += menor_i[i];
        sum -= (menor_i[i] * m);
        ans.push_back(mv{0, i, menor_i[i]});
        for(int j=0; j<m; j++) {
            menor_j[j] = min(menor_j[j], a[i][j] - menor_i[i]);
        }
    }
    for(int j=0; j<m; j++) {
        mv1 += menor_j[j];
        sum -= (menor_j[j] * n);
        ans.push_back(mv{1, j, menor_j[j]});
    }

    for(int i=0; i<n; i++)
        menor_i[i] = 9999999;
    for(int j=0; j<m; j++)
        menor_j[j] = 9999999;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            menor_i[i] = min(menor_i[i], a[i][j]);
            menor_j[j] = min(menor_j[j], a[i][j]);
        }
    }

    for(int j=0; j<m; j++) {
        mv2 += menor_j[j];
        sum2 -= (menor_j[j] * n);
        ans2.push_back(mv{1, j, menor_j[j]});
        for(int i=0; i<n; i++) {
            menor_i[i] = min(menor_i[i], a[i][j] - menor_j[j]);
        }
    }
    for(int i=0; i<n; i++) {
        mv2 += menor_i[i];
        sum2 -= (menor_i[i] * m);
        ans2.push_back(mv{0, i, menor_i[i]});
    }

    if(sum && sum2) puts("-1");
    else if(sum) print(mv2, 2);
    else if(sum2) print(mv1, 1);
    else if(mv1 > mv2) print(mv2, 2);
    else print(mv1, 1);

    return 0;
}