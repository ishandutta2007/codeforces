#include<bits/stdc++.h>
#define maxn 100001

using namespace std;
int a[maxn*17*20][2],n,o,k,w,d,u,sz[maxn*17*20],p,m;
bool f[maxn];

void insert_(int x,int y)
{
    sz[x]++;
    for (int i=16;i>=0;i--){
        int j=(y&(1<<i))>0;
        if (!a[x][j]) a[x][j]=p++;
        x=a[x][j]; sz[x]++;
    }
}

bool bo(int x,int y,int z){
    if (x==0||z<=0) return false;
    if (z>=(1<<(y+1))) return true;
    return bo(a[x][0],y-1,z)||bo(a[x][1],y-1,z-(1<<y));
}

int qry(int x,int y,int z)
{
    int c=16,rt=0;
    if (!bo(x,c,y)) return -1;
    while (c>=0){
        if (z&(1<<c)){
            if (a[x][0]) x=a[x][0]; else x=a[x][1],rt|=(1<<c),y-=(1<<c);
        }
        else {
            if (bo(a[x][1],c-1,y-(1<<c))) x=a[x][1],rt|=(1<<c),y-=(1<<c); else x=a[x][0];
        }
        c--;
    }
    return rt;
}

int main()
{
    cin >> n; p=maxn;
    while (n--){
        cin>>o;
        if (o==1){
            cin >> k;
            if (!f[k]){
                for (int j=1;j*j<=k;j++) if (k%j==0){
                    insert_(j,k);
                    if (j*j<k) insert_(k/j,k);
                }
                f[k]=true;
            }
        }
        else {
            cin >> w >> k >> u;
            if (w%k) cout << -1 << endl; else cout << qry(k,u-w+1,w) << endl;
        }
    }
    return 0;
}