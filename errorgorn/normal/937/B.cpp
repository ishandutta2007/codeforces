#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int p,n;

const int witness[]={2,7,61};
const int witness_size=sizeof(witness)/sizeof(int); ///thanks to Roberto for this

bool isPrime(int i){
    ///check for the simple cases
    if (i==1) return false;
    if (i==2) return true;
    if (!(i&1)) return false;
    for (int x=0;x<witness_size;x++){
        if (witness[x]==i) return true;
    }

    vector<int> pow;  ///this holds the bits of i with all the trailing zeros striped off
    int s=0; ///number of trailing zeros

    int _i=i-1;
    while (!(_i&1)){
        s++;
        _i>>=1;
    }

    while (_i){
        pow.push_back(_i&1);
        _i>>=1;
    }

    long long curr;
    for (int x=0;x<witness_size;x++){
        curr=1;
        for (vector<int>::reverse_iterator it=pow.rbegin();it!=pow.rend();it++){
            if (*it){
                curr=(curr*curr)%i;
                curr=(curr*witness[x])%i;
            }
            else{
                curr=(curr*curr)%i;
            }
        }

        if (curr==1 || curr==i-1) goto _end;

        for (int x=1;x<s;x++){
            if (curr!=i-1) {
                curr=(curr*curr)%i;
                if (curr==1) return false;
            }
            else goto _end;
        }
        if (curr!=i-1) return false;
        _end:;
    }

    return true;
}



int main(){
    scanf("%d%d",&p,&n);
    int sqrtn=sqrt(n);

    if (p>sqrtn){
        for (int x=n;x>p;x--){
            if (isPrime(x)){
                printf("%d\n",x);
                return 0;
            }
        }
    }
    else{
        for (int x=n;x>=0;x--){
            for (int y=2;y<=p;y++){
                if (x%y==0) goto _e;
            }
            printf("%d\n",x);
            return 0;
            _e:;
        }
    }
    printf("-1\n");
}