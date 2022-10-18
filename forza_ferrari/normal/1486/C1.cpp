#include<iostream>
#include<cstdio>
using namespace std;
int n,lst;
void dfs(int l,int r)
{
    if(l==r)
    {
        cout<<"! "<<l<<endl;
        return;
    }
    int mid=(l+r)>>1;
    if(lst<l)
    {
        if(lst==mid)
        {
            dfs(mid+1,r);
            return;
        }
        cout<<"? "<<lst<<" "<<mid<<endl;
        int p;
        cin>>p;
        if(p==lst)
            dfs(l,mid);
        else
            dfs(mid+1,r);
        return;
    }
    if(lst>r)
    {
        if(mid+1==lst)
        {
            dfs(l,mid);
            return;
        }
        cout<<"? "<<mid+1<<" "<<lst<<endl;
        int p;
        cin>>p;
        if(p==lst)
            dfs(mid+1,r);
        else
            dfs(l,mid);
        return;
    }
    if(lst<=mid)
    {
        if(l==mid)
        {
            dfs(mid+1,r);
            return;
        }
        cout<<"? "<<l<<" "<<mid<<endl;
        int p;
        cin>>p;
        if(p==lst)
            dfs(l,mid);
        else
            dfs(mid+1,r);
        return;
    }
    if(mid+1==r)
    {
        dfs(l,mid);
        return;
    }
    cout<<"? "<<mid+1<<" "<<r<<endl;
    int p;
    cin>>p;
    if(p==lst)
        dfs(mid+1,r);
    else
        dfs(l,mid);
}
int main()
{
    cin>>n;
    cout<<"? 1 "<<n<<endl;
    cin>>lst;
    dfs(1,n);
    return 0;
}