//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[57][57];
int main(){
	int n;
	scanf("%d",&n);
	n*=4;
	n++;
	rb(i,1,n){
		int xi,yi;
		scanf("%d %d",&xi,&yi);
		a[xi][yi]=1;
	} 
	rb(i,0,55){
		rb(j,0,55){
			rb(k,i,55){
				rb(l,0,j){
					int tot=0;
					rb(h,i,k){
						rb(y,l,j){
							if(h!=i&&h!=k&&y!=l&&y!=j) continue;
							tot+=a[h][y];
						}
					}
					if(tot==n-1){
						rb(h,i,k){
						rb(y,l,j){
							if(h!=i&&h!=k&&y!=l&&y!=j) continue;
							a[h][y]=0;
						}
						}
						rb(h,0,55){
							rb(y,0,55){
								if(a[h][y]){
//									cout<<"-"<<i<<","<<j<<"&"<<k<<","<<l<<endl;
									printf("%d %d\n",h,y);
									return 0;
								}
							}
						}
						return 0;
					}
				}
			}
		}
	}
	return 0;
}