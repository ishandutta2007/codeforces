#include<stdio.h>
#include<algorithm>
#include<set>
int n,m,q;
struct edge{
	int a,b,color;
	bool operator<(const edge&r)const{
		return color<r.color;
	}
};
edge ep[100100];
int sd[200100][2];
int sn;
int sdn;
int qry[100100][2];
int qn[100100];
int qlist[100100];
int uft[100100];
int chk[100100];
int vchk[100100];
int ans[100100];
int psdl[100100];
int sdl[100100];
int sdln;
int spn[100100];
int splist[200100];
int schk[100100];
std::set<int>sa[100100];
int uftf(int x){
	if(x==uft[x])return x;
	return uft[x]=uftf(uft[x]);
}
int main(){
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&ep[i].a,&ep[i].b,&ep[i].color);
	}
	std::sort(ep,ep+m);
	for(i=1;i<=n;i++){
		uft[i]=i;
	}
	j=0;
	for(i=0;i<=m;i++){
		for(k=j;k<m&&ep[k].color==i;k++);
		for(l=j;l<k;l++){
			if(uftf(ep[l].a)!=uftf(ep[l].b)){
				uft[uftf(ep[l].a)]=uftf(ep[l].b);
			}
		}
		for(l=j;l<k;l++){
			if(vchk[uftf(ep[l].a)]==0){
				sn++;
				vchk[uftf(ep[l].a)]=sn;
			}
			if(chk[ep[l].a]==0){
				sa[vchk[uftf(ep[l].a)]-1].insert(ep[l].a);
				sd[sdn][0]=ep[l].a;
				sd[sdn][1]=vchk[uftf(ep[l].a)]-1;
				sdn++;
			}
			if(vchk[uftf(ep[l].b)]==0){
				sn++;
				vchk[uftf(ep[l].b)]=sn;
			}
			if(chk[ep[l].b]==0){
				sa[vchk[uftf(ep[l].b)]-1].insert(ep[l].b);
				sd[sdn][0]=ep[l].b;
				sd[sdn][1]=vchk[uftf(ep[l].b)]-1;
				sdn++;
			}
			chk[ep[l].a]=1;
			chk[ep[l].b]=1;
		}
		for(l=j;l<k;l++){
			vchk[ep[l].a]=0;
			vchk[ep[l].b]=0;
			chk[ep[l].a]=0;
			chk[ep[l].b]=0;
			uft[ep[l].a]=ep[l].a;
			uft[ep[l].b]=ep[l].b;
		}
		j=k;
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
		qn[qry[i][0]+2]++;
	}
	for(i=0;i<n+3;i++){
		qn[i+1]+=qn[i];
	}
	for(i=0;i<q;i++){
		qlist[qn[qry[i][0]+1]]=i;
		qn[qry[i][0]+1]++;
	}
	for(i=0;i<sdn;i++){
		spn[sd[i][0]+2]++;
	}
	for(i=0;i<n+3;i++){
		spn[i+1]+=spn[i];
	}
	for(i=0;i<sdn;i++){
		splist[spn[sd[i][0]+1]]=sd[i][1];
		spn[sd[i][0]+1]++;
	}
	for(i=1;i<=n;i++){
		if(qn[i+1]-qn[i]>100){
			for(j=1;j<=n;j++){
				psdl[j]=0;
			}
			for(j=0;j<=sn;j++){
				schk[j]=0;
			}
			sdln=0;
			for(j=spn[i];j<spn[i+1];j++){
				schk[splist[j]]=1;
			}
			for(j=0;j<sdn;j++){
				if(schk[sd[j][1]]==1){
					psdl[sd[j][0]]++;
				}
			}
			for(j=qn[i];j<qn[i+1];j++){
				ans[qlist[j]]=psdl[qry[qlist[j]][1]];
			}
		}
		else{
			for(j=qn[i];j<qn[i+1];j++){
				for(k=spn[i];k<spn[i+1];k++){
					if(sa[splist[k]].lower_bound(qry[qlist[j]][1])!=sa[splist[k]].end()&&*sa[splist[k]].lower_bound(qry[qlist[j]][1])==qry[qlist[j]][1]){
						ans[qlist[j]]++;
					}
				}
			}
		}
	}
	for(i=0;i<q;i++){
		printf("%d\n",ans[i]);
	}
}