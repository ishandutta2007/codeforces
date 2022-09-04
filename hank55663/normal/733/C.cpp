#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define x first
#define y second  
using namespace std;
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	int a[505];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int k;
	scanf("%d",&k);
	int b[505];
	memset(b,0,sizeof(b));
	for(int i=0;i<k;i++)
	scanf("%d",&b[i]);
	int sum=0,last=0,sub=0;
	vector<pair<int,char> > ans;
	int ok=1,j=0;
	for(int i=0;i<=n;i++){
		if(j==k)
		{
			ok=0;
			break;
		}
		if(sum==b[j]){
			if(last!=i-1){
				int maxn=0,maxi=0;
				for(int k=last;k<i;k++)
				{
					if(maxn<a[k]){
						maxn=a[k];
						maxi=k;
					}	
					else if(maxn==a[k]){
						if(k+1<i&&a[k+1]<a[k])
						{
							maxi=k;
						}
						if(k-1>=last&&a[k-1]<a[k]){
							maxi=k;
						}
					}
				}
				if((a[maxi]==a[maxi+1]||maxi+1>=i)&&(a[maxi]==a[maxi-1]||maxi-1<last)){
				/*	if(n==500&&a[0]==885492)
					printf("1");*/
					ok=0;
					//printf("1");
				}
				else if(maxi+1<i&&a[maxi]>a[maxi+1])
				{
					for(int k=maxi+1;k<i;k++)
					ans.pb(mp(maxi-last+j,'R'));
					for(int k=maxi;k>last;k--)
					ans.pb(mp(k-last+j,'L'));
				}
				else{
					ans.pb(mp(maxi-last+j,'L'));
					maxi--;
					for(int k=maxi+2;k<i;k++)
					ans.pb(mp(maxi-last+j,'R'));
					for(int k=maxi;k>last;k--)
					ans.pb(mp(k-last+j,'L'));
				}
			}
			j++;
			sum=0;
			last=i;
		} 
		if(sum>b[j])
		ok=0;//printf("%d %d",sum,b[j]);
		if(i==n){
			if(sum!=0)
			ok=0;
			break;
		}
		sum+=a[i];
	}
	if(j!=k)
	ok=0;
	if(!ok)
	printf("NO\n");
	else{
		printf("YES\n");
		for(vector<pair<int,char> >::iterator it=ans.begin();it!=ans.end();it++)
		printf("%d %c\n",it->x+1,it->y);
	}
}