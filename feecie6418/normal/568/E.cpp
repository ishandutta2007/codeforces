#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],d[100005],len,f[100005],dpos[100005],lst[100005],vst[100005];
//f[i]:i
//d[i]:i
//dpos[i]:d[i]
//lst[i]:i 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			if(!len||d[len]<a[i])d[++len]=a[i],f[i]=len,dpos[len]=i,lst[i]=dpos[len-1];
			else {
				int pos=lower_bound(d+1,d+len+1,a[i])-d;
				d[pos]=a[i],f[i]=pos,lst[i]=dpos[pos-1],dpos[pos]=i;
			}
		}
		else {
			lst[i]=-1;
			for(int k=m,j=len;k>=1;k--){
				if(d[len]<b[k]||!len){
					d[j=++len]=b[k],dpos[len]=i;
					continue;
				}
				while(j&&d[j-1]>=b[k])j--;
				d[j]=b[k],dpos[j]=i;
			}
		}
	}
	int i=dpos[len],curl=len;
	if(a[i]==-1)a[i]=b[m],vst[m]=1;
	for(;i;){
		if(lst[i]!=-1){
			if(a[lst[i]]==-1){
				for(int j=m;j>=1;j--)
					if(!vst[j]&&b[j]<a[i]){
						a[lst[i]]=b[j],vst[j]=1;
						break;
					}
			}
			i=lst[i],curl--;
			continue;
		}
		bool flag=0;
		for(int j=i-1;j>=0&&!flag;j--)if(a[j]!=-1&&f[j]+1==curl&&a[j]<a[i])flag=1,i=j,curl--;
		if(flag)continue;
		for(int j=i-1;j>=1;j--){
			if(a[j]==-1){
				for(int k=m;k>=1;k--){
					if(!vst[k]&&b[k]<a[i]){
						a[j]=b[k],vst[k]=1,i=j,curl--;
						break;
					}
				}
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			for(int j=m;j>=1;j--)
				if(!vst[j]){
					a[i]=b[j],vst[j]=1;
					break;
				}
		}
		cout<<a[i]<<' ';
	}
}