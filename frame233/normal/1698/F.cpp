#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=505;typedef std::pair<int,int> pi;
int oa[N],a[N],b[N],pos[N];std::vector<pi> ans;
void apply(int l,int r){assert(a[l-1]==a[r+1]),ans.pb({l-1,r+1}),std::reverse(a+l,a+r+1);}
void MAIN(){
	int n;read(n);ans.clear();
	for(int i=1;i<=n;++i)read(a[i]);
	memcpy(oa,a,(n+3)<<2);
	for(int i=1;i<=n;++i)read(b[i]);
	std::multiset<std::pair<int,int>> S1,S2;
	for(int i=1;i<n;++i){
		int x=a[i],y=a[i+1];if(x>y)std::swap(x,y);
		S1.insert({x,y});
		x=b[i],y=b[i+1];if(x>y)std::swap(x,y);
		S2.insert({x,y});
	}
	if(S1!=S2||a[1]!=b[1]||a[n]!=b[n])return puts("NO"),void();
	puts("YES");
	for(int i=2;i<n;++i)if(a[i]!=b[i]){
		bool flag=0;
		for(int j=i+1;j<n;++j){
			if(a[j]==b[i]&&a[j+1]==a[i-1]){
				flag=1,apply(i,j);break;
			}
		}
		if(!flag){
			for(int j=i+1;j<=n;++j)if(a[j]==b[i]&&a[j-1]==a[i-1]){
				for(int k=i+1;k<j-1;++k)if(a[k]==b[i]){
					apply(k+1,j-1),apply(i,k),flag=1;
					break;
				}
				if(flag)break;
				memset(pos,0,(n+3)<<2);for(int k=j+1;k<=n;++k)pos[a[k]]=k;
				for(int k=i-1;k<j-1;++k){
					if(pos[a[k]]){
						apply(k+1,pos[a[k]]-1),apply(i,k+pos[a[k]]-j);
						flag=1;break;
					}
				}
				if(flag)break;
			}
		}
	}
	printf("%d\n",SZ(ans));
	for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}