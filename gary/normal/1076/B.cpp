//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
#define niv vector<LL>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const LL INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
map<int,int> M;

bool isPrime(LL num) {
    if (num <= 3) {
        return num > 1;
    }
    // 6
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    for (LL i = 5; i*i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int main(){
	LL n;
	cin>>n;
	if(n&1==0){
		cout<<(n<<1)<<endl;
		return 0;
	}
	if(isPrime(n)){
		cout<<1<<endl;
		return 0;
	}
	LL is;
	for(LL i=2;i<=n;i++){
		if(n%i==0){
			LL num1,num2;
			num1=i;
			if(isPrime(num1)){
				is=num1;
				break;
			}
		}
	}
	LL cost=n-is;
	cout<<cost/2+1<<endl;
	return 0;
}