#include <cstdio>
#include <stack>
using namespace std;
long long n;
stack<int> s;
int main(){
    scanf("%lld",&n);
    long long curr=0;
    long long next=9;
    long long digits=1;
    while (true){
        if ((next-curr)*digits<n){
            n-=(next-curr)*digits;
            curr=next;
            next=next*10+9;
            digits++;
        }
        else{
            curr+=n/digits;
            n%=digits;
            //printf("%lld %lld %lld\n",curr,digits,n);
            if (!n){
                printf("%d\n",curr%10);
            }
            else{
                curr++;
                while (curr){
                    s.push(curr%10);
                    curr/=10;
                }
                for (int x=1;x<n;x++) s.pop();
                printf("%d\n",s.top());
            }
            break;
        }
    }
}