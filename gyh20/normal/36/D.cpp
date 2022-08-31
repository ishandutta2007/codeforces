#include<cstdio>
using namespace std;
int t,k,a,b;
int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&t,&k);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a>b)a^=b^=a^=b;
        if(!(a%(k+1))||(b-a+a/(k+1)*(k!=1))%2)puts("+");
        else puts("-");
    }
}