#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e5+10;
const int M=998244353;
const int N=4;
bool f[6005][6005];
int n,p[6005],q[6005],id[16],a[6005];
ll ans,cnt[16],c[6005][16][2];
int w(int x,int y){
    if (x<0) x=-x;
    if (y<0) y=-y;
    int d=__gcd(x,y);
    return d-1;
}
bool check(int a,int b,int c,int d,int e,int f){
    int S=abs((a*d-b*c)+(c*f-d*e)+(e*b-f*a));
    //if (S&1) return 0;
    int res=(S-1-w(a-c,b-d)-w(c-e,d-f)-w(e-a,f-b));
    assert(res%2==0);
    res/=2;
    return res%2==1;
}
int area(int a,int b,int c,int d,int e,int f){
    int S=abs((a*d-b*c)+(c*f-d*e)+(e*b-f*a));
    return S/2;
}
int main(){
    cin >> n;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            id[i*4+j]=(i&1)*2+(j&1);
    for (int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        x+=N; y+=N;
        p[i]=x; q[i]=y;
        int mask=(x%N)*N+(y%N);
        a[i]=mask;
        cnt[mask]++;
    }
    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++) if (a[i]!=a[j]){
        int x=abs(__gcd(p[i]-p[j],q[i]-q[j]));
        x=(x-1)/2;
        c[i][a[j]][x&1]++;
        c[j][a[i]][x&1]++;
    }
    for (int i=0;i<N*N;i++)
    for (int j=i;j<N*N;j++)
    for (int k=j;k<N*N;k++) {
        if (id[i]!=id[j]||id[j]!=id[k]) continue;
        if (!check(i/N,i%N,N+j/N,j%N,k/N,N+k%N)) continue;
        if (i==j&&j==k) ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
        else if (i==j) ans+=cnt[i]*(cnt[i]-1)*cnt[k]/2;
        else if (j==k) ans+=cnt[i]*cnt[j]*(cnt[j]-1)/2;
        else ans+=cnt[i]*cnt[j]*cnt[k];
    }
    for (int i=0;i<n;i++)
    for (int j=0;j<N*N;j++)
    for (int k=j;k<N*N;k++){
        if (id[a[i]]==id[j]||id[j]!=id[k]) continue;
        bool o=1;
        if (area(p[i],q[i],j/N,j%N,k/N,k%N)&1) o^=1;
        int x=abs(__gcd(j/N-k/N,j%N-k%N));
        if (x&2) o^=1;
        if (j==k){
            if (!o) ans+=c[i][j][0]*(c[i][j][0]-1)/2+c[i][j][1]*(c[i][j][1]-1)/2;
            else ans+=c[i][j][0]*c[i][j][1];
        } else {
            if (!o) ans+=c[i][j][0]*c[i][k][0]+c[i][j][1]*c[i][k][1];
            else ans+=c[i][j][0]*c[i][k][1]+c[i][j][1]*c[i][k][0];
        }
    }
    cout << ans << endl;
}