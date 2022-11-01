#include <iostream>
#include<bits/stdc++.h>
# define fo(i,n) for(int i=0;i < (n);i++)
#define ll long long
using namespace std;
 vector<int>v[2005];
 int hmax[2005];
void maxheight(int k,int root,int height){
    //if(k==1)cout<<root<<"FF";
    if(hmax[k]<height){hmax[k]=height;}
    for(int i=0;i<v[root].size();i++){
        //if(k==4)cout<<"fuck";
        maxheight(k,v[root][i],height+1);
    }
    return ;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(temp==-1);
        else {
            v[temp].push_back(i);
        }
    }
    //cout<<v[3].size()<<endl;
    //int hmax[n+1];
    for(int i=0;i<=n;i++)hmax[i]=0;
    for(int i=1;i<=n;i++){maxheight(i,i,1); }
    sort(hmax,hmax+n+1);
    cout<<hmax[n];
    return 0;
}