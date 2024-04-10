#include<bits/stdc++.h>
#define maxn 50002
#define M 1000000007

using namespace std;
typedef long long ll;
struct node{
    ll pos,e,h;
};
node q[maxn];
bool cmp(node u,node v)
{
    return u.pos<v.pos;
}
struct matrix{
    ll a[3][3];
    matrix operator *(matrix const &u) const{
        matrix tmp;
        for (int i=0;i<3;i++) for (int j=0;j<3;j++) tmp.a[i][j]=0;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                for (int k=0;k<3;k++)
                    (tmp.a[i][j]+=a[i][k]*u.a[k][j])%=M;
        return tmp;
    }
};
struct vec{
    ll w[3];
    vec operator *(matrix const &u) const{
        vec tmp;
        for (int i=0;i<3;i++) tmp.w[i]=0;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                (tmp.w[i]+=u.a[i][j]*w[j])%=M;
        return tmp;
    }
};
ll n,m,k,p,l,r,cnt,s[3];
matrix b,c,d,o,f;
vec ans;

matrix pow_(matrix u,ll v)
{
    matrix tmp=o;
    while (v){
        if (v&1) tmp=tmp*u;
        u=u*u;
        v>>=1;
    }
    return tmp;
}

int main()
{
    b.a[0][0]=1; b.a[0][1]=1; b.a[0][2]=0;
    b.a[1][0]=1; b.a[1][1]=1; b.a[1][2]=1;
    b.a[2][0]=0; b.a[2][1]=1; b.a[2][2]=1;
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) o.a[i][j]=(i==j);
    scanf("%lld%lld",&n,&m);
    for (int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&p,&l,&r); p--;
        q[cnt].pos=l; q[cnt].h=p; q[cnt++].e=1;
        q[cnt].pos=r+1; q[cnt].h=p; q[cnt++].e=-1;
    }
    sort(q,q+cnt,cmp); p=1;
    ans.w[0]=0; ans.w[1]=1; ans.w[2]=0;
    q[cnt].pos=m+1,q[cnt].h=q[cnt].e=0; c=b;
    ans=ans*pow_(b,q[0].pos-2);
    for (int i=0;i<cnt;i++)
    {
        s[q[i].h]+=q[i].e;
        c=b; for (int j=0;j<3;j++) if (s[j]) for (int jj=0;jj<3;jj++) c.a[j][jj]=0;
        ans=ans*pow_(c,q[i+1].pos-q[i].pos);
        /*
        for (int j=0;j<3;j++)
        {
            for (int jj=0;jj<3;jj++) printf("%d ",c.a[j][jj]);
            printf("\n");
        }
        for (int j=0;j<3;j++) printf("%d ",s[j]); printf("&\n");
        for (int j=0;j<3;j++) printf("%d ",ans.w[j]); printf("!\n");
        */
    }
    printf("%lld\n",ans.w[1]);

    return 0;
}