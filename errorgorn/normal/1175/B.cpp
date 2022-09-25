#include <cstdio>
#include <stack>
#include <utility>
using namespace std;
typedef pair<long long,long long> ii;
int n;
char c;
stack<ii> s;
long long k;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    s.push(ii(1,0));
    while (n--){
        getchar();
        c=getchar();
        getchar();
        getchar();
        if (c=='a'){
            s.top().second++;
        }
        else if (c=='e'){
            k=s.top().first*s.top().second;
            s.pop();
            s.top().second+=k;
        }
        else if (c=='f'){
            scanf("%lld",&k);
            s.push(ii(k,0));
        }
        if (s.top().second>4294967295){
            printf("OVERFLOW!!!\n");
            return 0;
        }
    }
    printf("%lld\n",s.top().second);
}