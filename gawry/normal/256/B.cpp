#include<cstdio>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int n,x,y,c,sum,ans;
int f(int a,int b){
  if(a+b>=0)return (a+b)/2;
	return (a+b-1)/2;
}
void add(int x0,int y0,int x1,int y1){
//cout<<x0<<","<<y0<<" "<<x1<<","<<y1<<endl;
  if(x0>x1){
    swap(x0,x1);
		swap(y0,y1);
	}
  if(y0>y1){
		y0=n-1-y0;
		y1=n-1-y1;
	}
	if(x0>=n||x1<0||y0>=n||y1<0)return;
	if(x0>=0&&x1<n&&y0>=0&&y1<n){
		//			cout<<"add "<<(x1-x0+1)<<endl;
		sum+=x1-x0+1;
		return;
	}
	add(x0,y0,f(x0,x1),f(y0,y1));
	add(f(x0,x1)+1,f(y0,y1)+1,x1,y1);
}
main(){
  scanf("%d %d %d %d",&n,&x,&y,&c);
	--x;--y;
  sum=1;
	ans=0;
	while(sum<c){
		++ans;
    add(x-ans,y,x-1,y+ans-1);
    add(x,y+ans,x+ans-1,y+1);
    add(x+ans,y,x+1,y-ans+1);
    add(x,y-ans,x-ans+1,y-1);
	//	cout<<ans<<" "<<sum<<endl;
	}
  printf("%d\n",ans);
}