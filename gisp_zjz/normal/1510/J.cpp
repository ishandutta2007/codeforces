#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=3e6+10;
char s[maxn];
int n,m;
vector<int> ans,a;
void print(){
    printf("%d\n",(int)ans.size());
    for (auto x:ans) printf("%d ",x);puts("");
}
bool noprofile(){
	for (int i=1;i<=n;i++) if (s[i]=='#') return 0;
	return 1;
}
void add1(int x){
	if (x&1) ans.pb(2),x-=3;
	while (x) ans.pb(1),x-=2;
}
bool work0(){
    if (s[1]!='#'||s[n]!='#') return 0;
    int last=0;
    for (int i=2;i<=n;i++){
		if (s[i-1]=='_'&&s[i]=='_') return 0;
		if (s[i]=='_'){
			ans.pb(i-last-1);
			last=i;
		}
    }
    ans.pb(n-last);
    print();
    return 1;
}
bool work1(){
	if (a[0]%2==0||a[m]%2==0) return 0;
	for (int i=2;i<=m-2;i+=2) if (a[i]%2==1) return 0;
	add1(a[0]-1);
    for (int i=1;i<=m-1;i++){
		if (i%2==0){
			add1(a[i]-2);
		} else {
			ans.pb(a[i]+1);
		}
    }
	add1(a[m]-1);
	print();
	return 1;
}
bool work2(){
	if (!(a[0]==2||a[0]>=4)) return 0;
	if (!(a[m]==2||a[m]>=4)) return 0;
	for (int i=2;i<=m-2;i+=2) if (!(a[i]==3||a[i]>=5)) return 0;
	add1(a[0]-2);
    for (int i=1;i<=m-1;i++){
		if (i%2==0){
			add1(a[i]-3);
		} else {
			ans.pb(a[i]+2);
		}
    }
	add1(a[m]-2);
	print();
	return 1;
}
bool work3(){
	if (!(a[0]==3||a[0]>=5)) return 0;
	if (!(a[m]==3||a[m]>=5)) return 0;
	for (int i=2;i<=m-2;i+=2) if (!(a[i]==4||a[i]>=6)) return 0;
	add1(a[0]-3);
    for (int i=1;i<=m-1;i++){
		if (i%2==0){
			add1(a[i]-4);
		} else {
			ans.pb(a[i]+3);
		}
    }
	add1(a[m]-3);
	print();
	return 1;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if (s[1]=='#'||s[n]=='#'){
        if (!work0()){
            puts("-1");
        }
	} else if (noprofile()){
		puts("0");
	} else {
		int last=0;
		for (int i=1;i<=n;i++)
			if (i==n||s[i]!=s[i+1]) a.pb(i-last),last=i;
		m=a.size()-1;
		if (!work1()&&!work2()&&!work3()){
			puts("-1");
		}
	}
	return 0;
}