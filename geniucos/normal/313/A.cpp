#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,p,aux,i,lst;
vector < int > v;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
if(n>=0)
{
    printf("%d\n",n);
    return 0;
}
aux=n*-1;
while(aux)
{
    v.push_back(aux%10);
    aux/=10;
}
reverse(v.begin(),v.end());
if(v.size()==1)
{
    printf("0\n");
    return 0;
}
lst=v[v.size()-1];
if(v[v.size()-2]<lst) lst=v[v.size()-2];
p=0;
for(i=0;i<v.size()-2;i++)
    p=p*10+v[i];
p=p*10+lst;
p=p*-1;
printf("%d\n",p);
return 0;
}