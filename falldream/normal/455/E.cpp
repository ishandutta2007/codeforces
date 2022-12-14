#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pair<int,int> Q[MN+5];int tp;
int size,n,m,a[MN+5],Ans[MN+5],s[MN+5],block[MN+5],num=0,q[MN+5],top,b[MN+5],id[MN+5];
struct ques{int r,t,id;};
vector<ques> v[350][350];

double Calc(pair<int,int> x,pair<int,int> y)
{
    //	x.first * x + x.second = y.first * x + y.second
    //x = y.second - x.second / (x.first - y.first);
    return (double)(y.second-x.second)/(x.first-y.first);
}
int Calc(int x,int t,int r){return s[r]-s[x]+a[x]*(t-(r-x));}
void Add(int ID,int a,int b)
{
    while(tp>1&&Calc(Q[tp-1],Q[tp])>=Calc(Q[tp],make_pair(a,b))) --tp;
    id[++tp]=ID;Q[tp]=make_pair(a,b);
}
int Bl(int r,int t)
{
    int l=r-t+1,res=2e9;
    for(int i=r;i>=l;--i) res=min(res,Calc(i,t,r));
    return res;
}
int Solve(int x)
{
    //	cout<<"Solve"<<x<<endl;
    //	cout<<"begin bianli"<<endl;
    //	for(int i=1;i<=tp;++i) printf("%d %d\n",Q[i].first,Q[i].second);
  //  int ans=2e9;
  //  for(int i=1;i<=tp;++i) ans=min(ans,x*Q[i].first+Q[i].second);
  //  return ans;
    int l=1,r=tp,res=2e9;
    while(l<=r)
    {
        int mid=l+r>>1;double pt;
        //		cout<<mid<<" "<<Q[mid].first<<" "<<Q[mid].second<<endl;
        res=min(res,x*Q[mid].first+Q[mid].second);
        pt=(mid==1?-1e9:Calc(Q[mid-1],Q[mid]));
        if(pt<=x) l=mid+1; else r=mid-1;
    }
    for(int i=0;i<=5;++i) if(l+i<=tp) res=min(res,x*Q[l+i].first+Q[l+i].second);
    return res;
}

int main()
{
    n=read();size=sqrt(n);
    for(int i=1;i<=n;++i) a[i]=read(),s[i]=s[i-1]+a[i],block[i]=(i-1)/size+1;
    m=read();num=block[n];
    for(int i=1;i<=m;++i)
    {
        int t=read(),r=read();
        //	cout<<block[r-t+1]<<" "<<block[r]<<endl;
        if(block[r-t+1]+1>=block[r]) {Ans[i]=Bl(r,t);continue;}
        int b1=block[r-t+1]+1,b2=block[r]-1;
       // cout<<b1<<" "<<b2<<" "<<i<<endl;
        v[b1][b2].push_back((ques){r,t,i});
    }
    for(int i=1;i<=num;++i)
    {
        top=tp=0;int now=1e9;//memset(b,0,sizeof(b));
        for(int j=i;j;--j)
        {
            int l=(j-1)*size+1,r=min(n,j*size);
            //cout<<"beginSolve"<<j<<" "<<i<<endl;
            for(int k=r;k>=l;--k) if(a[k]<now)
            {
                //	while(top&&a[k]<=a[q[top]]) b[q[top--]]=1;q[++top]=k;
                //	while(tp&&b[id[tp]]) --tp;
                //	cout<<i<<" "<<j<<" Add "<<k<<" "<<a[k]<<" "<<a[k]*k+s[n]-s[k]<<endl;
                Add(k,a[k],a[k]*k-s[k]);
                now=a[k];
            }
            for(int k=0;k<v[j][i].size();++k)
            {
                	//cout<<i<<" "<<j<<" "<<"Find"<<v[j][i][k].id<<endl;
                Ans[v[j][i][k].id]=Solve(v[j][i][k].t-v[j][i][k].r)+s[v[j][i][k].r];
                //cout<<"FIrstFind"<<Ans[v[j][i][k].id]<<endl;
                for(int p=v[j][i][k].r;p>i*size;--p)
                    Ans[v[j][i][k].id]=min(Ans[v[j][i][k].id],Calc(p,v[j][i][k].t,v[j][i][k].r));	
                for(int p=(j-1)*size;p>=v[j][i][k].r-v[j][i][k].t+1;--p)
                    Ans[v[j][i][k].id]=min(Ans[v[j][i][k].id],Calc(p,v[j][i][k].t,v[j][i][k].r));
            }
        }
    }
    for(int i=1;i<=m;++i) printf("%d\n",Ans[i]);
    return 0;
}