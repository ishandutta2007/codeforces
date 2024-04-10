#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
//#include <omp.h>

#define ll long long

using namespace std;

char name[11][102];
int a[11][101],b[11][101],c[11][101];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d\n",&n,&m,&k);
    for(int i=0;i<n;++i) {
        scanf("%s\n",&name[i]);
        for(int j=0;j<m;++j)
            scanf("%d%d%d\n",&a[i][j],&b[i][j],&c[i][j]);
    }
    int ans=0;
    vector < pair<int,int> > v;
    for(int p1=0;p1<n;++p1)
        for(int p2=0;p2<n;++p2)
            if (p1!=p2) {
                v.clear();
                for(int i=0;i<m;++i)
                    v.push_back(make_pair(a[p1][i]-b[p2][i],c[p1][i]));
                sort(v.begin(),v.end());
                int cur=0,kk=k;
                for(int i=0;kk&&i<v.size();++i) {
                    if (v[i].first<0) {
                        while(v[i].second&&kk) {
                            kk--; v[i].second--;
                            cur-=v[i].first;
                        }
                    }
                }
                if (cur>ans) ans=cur;
            }
    printf("%d\n",ans);
    return 0;
}