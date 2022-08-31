#include<iostream>
#include<bitset>
using namespace std;
typedef unsigned long long ll;
int n,q;
bitset<7001>b[100001];
bitset<7001>bj[7001];
bitset<7001>bk[7001];
bitset<7001>tmp;
bitset<7001>mb[7001];
bool nsf[7001];
void in(int& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=2; i<=90 ;i++){
		for(int j=i*i; j<=7000 ;j+=i*i) nsf[j]=true;
	}
	for(int i=1; i<=7000 ;i++){
		for(int j=i; j<=7000 ;j+=i){
			bj[j][i]=true;
			if(!nsf[j/i]) mb[i][j]=true;
		}
	}
	in(n);in(q);
	for(int i=1; i<=q ;i++){
		int t,x,y,z;
		in(t);
		if(t==1){
			in(x);in(y);
			b[x]=bj[y];
		}
		else if(t==2){
			in(x);in(y);in(z);
			b[x]=b[z]^b[y];
		}
		else if(t==3){
			in(x);in(y);in(z);
			b[x]=b[z]&b[y];
		}
		else{
			in(x);in(y);
			tmp=b[x]&mb[y];
			cout << tmp.count()%2;
		}
	}
}