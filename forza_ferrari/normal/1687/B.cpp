#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[501],p[501],ans;
inline bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cout<<"? ";
        for(int j=1;j<=m;++j)
            cout<<(i==j);
        cout<<endl;
        cin>>a[i];
        ans+=a[i];
        p[i]=i;
    }
    sort(p+1,p+m+1,cmp);
    string s;
    s.resize(m);
    for(int i=0;i<m;++i)
        s[i]='0';
    int lst=0;
    for(int i=1;i<=m;++i)
    {
        s[p[i]-1]='1';
        cout<<"? "<<s<<endl;
        int x;
        cin>>x;
        if(x!=lst+a[p[i]])
            ans-=a[p[i]];
        lst=x;
    }
    cout<<"! "<<ans<<endl;
    return 0;
}