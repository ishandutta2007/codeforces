//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    if(a>b)swap(a,b);
    int c=max(0,a-b+a);
    printf("%d\n",max(0,a-b+a)*2/3+min(a,b-a));
    return 0;
}