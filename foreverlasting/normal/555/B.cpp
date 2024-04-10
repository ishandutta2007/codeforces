#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200010;
int N,M;
struct A
{
    LL l,r;
    int id;
    bool operator<(const A &a)const
    {
        return l<a.l;
    }
}a[maxn];
pair<LL,int> p[maxn];
set<pair<LL,int>> st;
int ans[maxn];
int main()
{
    scanf("%d%d",&N,&M);
    N--;
    if(M<N){printf("No\n");return 0;}
    LL l,r,ll=0,lr=0;
    cin>>ll>>lr;
    for(int i=1;i<=N;i++)
    {
        cin>>l>>r;
        a[i].l=l-lr;
        a[i].r=r-ll;
        a[i].id=i;
        ll=l,lr=r;
    }
    for(int i=1;i<=M;i++)
    {
        cin>>l;
        p[i]=make_pair(l,i);
    }
    sort(a+1,a+1+N);
    sort(p+1,p+1+M);
    for(int j=M,i=N;i>0;i--)
    {
        while(j>0&&p[j].first>=a[i].l)
            st.insert(p[j]),j--;
        set<pair<LL,int>>::iterator it=st.upper_bound(make_pair(a[i].r+1,0));
        if(it==st.begin())
        {
            printf("No\n");
            return 0;
        }
        it--;
        ans[a[i].id]=it->second;
        st.erase(it);
    }
    printf("Yes\n");
    for(int i=1;i<=N;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}