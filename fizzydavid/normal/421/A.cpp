#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define y0 qgoiqoeinfoiqwef
#define y1 vmpoqmeppjofaqoi
#define yn qoigmnioqonfopiq
#define ff first
#define ss second
bool a[111],b[111];
int n,x,y;
int main()
{
    cin>>n>>x>>y;
    int tmp;
    for(int i=1;i<=x;i++){cin>>tmp;a[tmp]=1;}
    for(int i=1;i<=y;i++){cin>>tmp;b[tmp]=1;}
    for(int i=1;i<=n;i++)if(a[i])cout<<"1 ";else cout<<"2 ";
//  system("pause");
    return 0;
}