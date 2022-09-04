#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
#define N 300005
#define rank Rank
char ss[N];
int heigh[N];
int sa[N];
int rank[N];
int length;
int val[30];
int c[N];   // counting sort array
int temp[2][N];
void suffix_array()
{
    int A = 250;          
    int* rank = temp[0];
    int* new_rank = temp[1];
    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<length; ++i) c[rank[i] = ss[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=length-1; i>=0; --i) sa[--c[ss[i]]] = i;
    for (int n=1; n<length; n*=2)
    {
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<length; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        int* sa2 = new_rank;       
        int r = 0;                  
        for (int i=length-n; i<length; ++i)   
            sa2[r++] = i;           
        for (int i=0; i<length; ++i)    
            if (sa[i] >= n)       
                sa2[r++] = sa[i] - n;
        for (int i=length-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
        new_rank[sa[0]] = r = 0;
        for (int i=1; i<length; ++i)
        {
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                sa[i-1]+n < length &&    // stable sort trick
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, new_rank);
        if (r == length-1) break;
        A = r + 1;
    }
}
void lcp_array()
{
    for (int i=0; i<length; ++i)
        rank[sa[i]] = i;
 
    for (int i=0, lcp=0,h=0; i<length; i++){
        if (rank[i] == 0)
            heigh[0] = 0;
        else
        {
            int j = sa[rank[i]-1];
            if (lcp > 0) lcp--,h--;
            while (ss[i+h] == ss[j+h]) lcp++,h++;
            heigh[rank[i]] = lcp;
      //		printf("%d %d\n",rank[i],lcp);
	    }
    }
}
int fl[200005];
int Findl(int a){
	if(fl[a]==a)
	return a;
	return fl[a]=Findl(fl[a]);
}
int fr[200005];
int Findr(int a){
	if(fr[a]==a)
	return a;
	return fr[a]=Findr(fr[a]);
}
int Si[200005];
vector<pii> v[200005];
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",ss);
	string s1;
	cin>>s1;
	length=n;
	reverse(ss,ss+n);
	reverse(s1.begin(),s1.end());
	suffix_array();
	lcp_array();
	for(int i=0;i<n;i++){
		if(s1[i]=='0')
		Si[rank[i]]=1;
	}
	for(int i=1;i<n;i++){
	//	printf("%d",heigh[i]);
		v[heigh[i]].pb(mp(i,i-1));
	} 
	for(int i=0;i<=n;i++){
		fl[i]=i;
		fr[i]=i;
	}
	LL Size=0,ans=0;
	for(int i=n;i>=1;i--){
		if(s1[n-i]=='0'){
			ans=max(ans,(LL)i);
		}
		for(vector<pii>::iterator it=v[i].begin();it!=v[i].end();it++){
			int l=Findl(it->x),r=Findr(it->y);
			LL tot=Si[l]+Si[r];
			fl[r]=l;
			fr[l]=r;
			Si[l]=tot;
			Si[r]=tot;
			Size=max(Size,tot);
		}
	//	printf("%d\n",Size);
		ans=max(ans,Size*i);
	} 
	printf("%I64d\n",ans);
	/*
	printf("\n");
	for(int i=0;i<n;i++)
	printf("%d ",sa[i]);
	*/
}