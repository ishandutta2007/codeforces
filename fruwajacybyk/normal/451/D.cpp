#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<complex>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
#define root(i,n) CD(cos(2*(i)*M_PI/(n)),sin(2*(i)*M_PI/(n)))


#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}

#define max_n 100005
#define CD complex<double>

using namespace std;

/*CD* FFT(CD* v ,int n){
    CD* result = new CD[n];
    FOR(i,0,n) result[i] = v[i];

    FOR(i,0,n){
        int j = 0;
        for(int k=1; k<n;k<<=1,j<<=1) if(k&i) j++;
        j>>=1;
        if(i<j) swap(result[i],result[j]);
    }
    int step=1, n_step = 0;
    while((1<<n_step)<n) n_step++;
    for(int step=1; step<n; step<<=1){
        --n_step;
        for(int i=0; i<n; i+=2*step) FOR(j,0,step){
            CD u = result[i+j], v = result[i+j+step];
            result[i+j] = u+v*root(j<<n_step,n);
            result[i+j+step] = u-v*root(j<<n_step,n);
        }
    }
    return result;
}
*/




int main(){
	char s[100005]; 
	scanf("%s",s);
	int n = strlen(s);
	
	int K = 1;
	while(K<n) K*=2;
	K*=2;

	int na = 0;
	int nb = 0;
	
	int a[2];
	int b[2];
	FOR(i,0,2) a[i] = b[i] = 0;


	FOR(i,0,n){
		if(s[i]=='a'){
			a[i%2]++; na++;
		}
		if(s[i]=='b'){
			b[i%2]++; nb++;
		}
	}
	
	lint res1 = a[0]*1LL*a[0]+a[1]*1LL*a[1]+b[0]*1LL*b[0]+b[1]*1LL*b[1]+na+nb;
	lint res2 = a[1]*1LL*a[0]+b[0]*1LL*b[1];

	printf("%I64d %I64d\n",res2,res1/2);



	return 0;
}