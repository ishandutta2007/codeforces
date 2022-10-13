#include<iostream>
#include<utility>
#include<cstdio>
#include<algorithm>
#include<vector>
#define fr(a,b,c) for(a=b;a<=c;a++)
#define pii pair<int,int>
using namespace std;

int m,n,k,t;
vector <pii> a;

bool cmp(pii i,pii j)
{
    return i.first<j.first || (i.first==j.first && i.second<j.second); 
}

int main()
{
    int i,x,y;
    cin >> m >> n >> k >> t;
    a.clear();
    fr(i,1,k)
    {
       scanf("%d%d",&x,&y);
       a.push_back(make_pair(x,y));
    }
    a.push_back(make_pair(m+1,n+1));
    sort(a.begin(),a.end(),cmp);
    while (t--)
    {
       scanf("%d%d",&x,&y);
       pii u=make_pair(x,y);  
       fr(i,0,k)
         if (!cmp(a[i],u))
         {
             if (a[i]==u) printf("Waste\n");
             else
             {
                int j=(x-1)*n+y-i;  
                j%=3;
                if (j==1) printf("Carrots\n");
                if (j==2) printf("Kiwis\n");
                if (!j) printf("Grapes\n");
             }
             break;             
         } 
    }
    //system("pause");
    return 0;
}