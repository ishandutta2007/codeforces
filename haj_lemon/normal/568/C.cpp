#include<bits/stdc++.h>
#define M 200010
#define N 210
#define N2 410
#define ll long long
using namespace std;
struct Info{int x,nx,y,ny;}e[M];
struct Onfo{int nu,ne;}a[M*2];
bool v1[N2],v3[N][2],v2[N2],vi[28];
int l,m,n,num,b[N2],st[N2],nst,lo[N2],df[N2],nu,bi[N2];
char ch;
string s;
void jb(int x,int y){
	a[++num].nu=y;a[num].ne=b[x];b[x]=num;
	a[++num].nu=x^1;a[num].ne=b[y^1];b[y^1]=num;
}
void tarjan(int x){
	lo[x]=df[x]=++num;v1[x]=v2[x]=0;st[++nst]=x;
	for (int y=b[x];y;y=a[y].ne){
		if (v1[a[y].nu]){tarjan(a[y].nu);lo[x]=min(lo[x],lo[a[y].nu]);}
		else{if (!v2[a[y].nu])lo[x]=min(lo[x],df[a[y].nu]);}
	}
	if (df[x]==lo[x]){
		nu++;
		while (st[nst]!=x){bi[st[nst]]=nu;v2[st[nst]]=1;nst--;}
		bi[st[nst]]=nu;v2[st[nst]]=1;nst--;
	}
}
bool pa(){
	num=0;
	for (int i=2;i<=n*2+1;i++) b[i]=0,v1[i]=v2[i]=1;
	for (int i=1;i<=n;i++){
		if (!v3[i][0]&&!v3[i][1]) return 0;
		if (v3[i][0]&&v3[i][1]) continue;
		if (v3[i][0])jb(i*2+1,i*2);else jb(i*2,i*2+1);
	}
	for (int i=1;i<=m;i++)jb(e[i].x*2+e[i].nx,e[i].y*2+e[i].ny);
	nu=num=0;for (int i=2;i<=n*2+1;i++)if (v1[i])tarjan(i);
	for (int i=1;i<=n;i++) if (bi[i*2]==bi[i*2+1]) return 0;
	return 1;
}
int main(){
	cin>>s;l=s.length();
	for (int i=0;i<l;i++)if (s[i]=='V') vi[i]=1;else vi[i]=0;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>e[i].x;
		cin>>ch;if (ch=='V')e[i].nx=1;else e[i].nx=0;
		cin>>e[i].y;
		cin>>ch;if (ch=='V')e[i].ny=1;else e[i].ny=0;
	}
	cin>>s;
	for (int i=n;i>=0;i--){
		memset(v3,0,sizeof(v3));
		for (int j=1;j<=i;j++)v3[j][vi[s[j-1]-'a']]=1;
		for (int j=i+2;j<=n;j++)
			for (int k=0;k<l;k++)v3[j][vi[k]]=1;
		if (i+1<=n)for (int k=s[i]-'a'+1;k<l;k++) v3[i+1][vi[k]]=1;
		if (pa()){
			for (int j=1;j<=i;j++) cout<<s[j-1];
			for (int j=i+1;j<=n;j++){
				if (j==i+1){
					if (v3[j][0]&&v3[j][1]){
						v3[j][vi[s[i]-'a'+1]^1]=0;
						if (pa())cout<<(char)(s[j-1]+1);
						else{
							v3[j][vi[s[i]-'a'+1]^1]=1;v3[j][vi[s[i]-'a'+1]]=0;
							for (int k=s[i]-'a'+1;k<l;k++)if (vi[k]!=vi[s[i]-'a'+1]){cout<<(char)('a'+k);break;}
						}						
					}else cout<<(char)(s[j-1]+1);
				}else{
					if (v3[j][0]&&v3[j][1]){
						v3[j][vi[0]^1]=0;
						if (pa())cout<<'a';
						else{
							v3[j][vi[0]^1]=1;v3[j][vi[0]]=0;
							for (int k=0;k<l;k++)if (vi[k]!=vi[0]){cout<<(char)('a'+k);break;}
						}
					}else cout<<'a';
				}
			}
			cout<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}