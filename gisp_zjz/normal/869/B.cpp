#include<bits/stdc++.h>
#define maxn 2020
#define maxm 505000
#define eps 1e-9

using namespace std;
typedef long long ll;

ll p,q,s;

int main()
{
    scanf("%I64d%I64d",&p,&q);
    if (q-p>10) printf("0\n");
    else{
        s=1;
        while (q!=p){
            s=s*(q%10)%10;
            q--;
        }
        printf("%I64d\n",s);
    }
    return 0;
}