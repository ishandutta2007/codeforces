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
int a[505];
vector<mp> path;
int flag[505];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
		flag[i]=(a[i]>=2)? 1:0;
	}
	int rec=-1;
	int last=INF;
	int fir=INF;
	rb(i,1,n){
		if(a[i]>=2){
			fir=(fir==INF)? i : fir;
			if(last!=INF){
				path.PB(II(i,last));
			}
			last=i;
			rec++;
			a[i]-=2;
		}
	}
	if(fir!=INF)a[fir]++;
	if(last!=INF)a[last]++;
	if(rec==-1){
		printf("NO\n");
		return 0;
	}
	rb(i,1,n){
		if(!flag[i]&&a[i]==1){
			rec++;
			path.PB(II(last,i));
			a[i]=INF;
			a[last]--;
			break;
		}
	}
	rb(i,1,n){
		if(!flag[i]&&a[i]==1){
			rec++;
			path.PB(II(fir,i));
			a[i]=INF;
			a[fir]--;
			break;
		}
	}
	int tot=0,tot1=0;
	rb(i,1,n){
		if(flag[i]){
			tot+=a[i];
		}
		if(!flag[i]&&a[i]!=INF){
			tot1++;
		}
	}
//	cout<<tot1<<" "<<tot<<endl;
	if(tot1>tot){
		printf("NO\n");
		return 0;
	}
	int l=1;
	rb(i,1,n){
		if(flag[i]){
			rb(j,1,a[i]){
				while((flag[l]||a[l]==INF)&&l<=n){
					l++;
				}
				if(l<=n){
					path.PB(II(l,i));
					l++;
				}
				
			}
		}
	}
	printf("YES %d\n",rec);
	int SZ= path.size();
	printf("%d\n",SZ);
	rb(i,1,SZ){
		printf("%d %d\n",path[i-1].FIR,path[i-1].SEC);
	}
	return 0;
}