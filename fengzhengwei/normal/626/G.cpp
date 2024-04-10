#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
int n,t,q,p[xx],l[xx];
struct Setbig
{
	struct nod{int id;dd val;
	bool operator<(const nod&w)const{return val==w.val?id<w.id:val<w.val;};
	bool operator==(const nod&b)const{return id==b.id&&val==b.val;}
	};//  
	
	priority_queue<nod>q1,q2;
	nod top()
	{
		while(q2.size()&&q1.top()==q2.top())q1.pop(),q2.pop();
		return q1.top();
	}
	int size(){return q1.size()-q2.size();}
	void insert(nod u){q1.push(u);}
	void erase(nod u){q2.push(u);}
	void clear(){while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();}
}B;
struct Setsmall
{
	struct nod{int id;dd val;
	bool operator<(const nod&w)const{return val==w.val?id<w.id:val>w.val;};
	bool operator==(const nod&b)const{return id==b.id&&val==b.val;}
	};//  
	priority_queue<nod>q1,q2;
	nod top()
	{
		while(q2.size()&&q1.top()==q2.top())q1.pop(),q2.pop();
		return q1.top();
	}
	int size(){return q1.size()-q2.size();}
	void insert(nod u){q1.push(u);}
	void erase(nod u){q2.push(u);}
	void clear(){while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();}
}S;

int cnt[xx];

dd get(int x,int y){return 1.0*p[x]*(l[x]<=y?0:1.0*(y+1)/(l[x]+y+1)-1.0*y/(l[x]+y));}
dd gtt(int x,int y){return 1.0*p[x]*min(y,l[x])/(l[x]+min(y,l[x]));}


//y 


int main(){
	n=read(),t=read(),q=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++)l[i]=read();
	
	//l 
	//l 
	
	dd ans=0;
	
	for(int i=1;i<=n;i++)B.insert({i,get(i,0)});
	
	while(t--)
	{
		int id=B.top().id;
		ans+=B.top().val;
		cnt[id]++;
		B.erase(B.top());
		if(cnt[id]!=1)S.erase({id,get(id,cnt[id]-2)});
		B.insert({id,get(id,cnt[id])});
		S.insert({id,get(id,cnt[id]-1)});
	}
	
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int x=read();
			ans-=gtt(x,cnt[x]);
			int id=x;
			if(cnt[x])S.erase({id,get(id,cnt[x]-1)});
			B.erase({id,get(id,cnt[x])});
			l[x]++;
			B.insert({id,get(id,cnt[x])});
			if(cnt[x])S.insert({id,get(id,cnt[x]-1)});
			ans+=gtt(x,cnt[x]);
		}
		else 
		{
			int x=read();
			ans-=gtt(x,cnt[x]);
			int id=x;
			if(cnt[x])S.erase({id,get(id,cnt[x]-1)});
			B.erase({id,get(id,cnt[x])});
			l[x]--;
			B.insert({id,get(id,cnt[x])});
			if(cnt[x])S.insert({id,get(id,cnt[x]-1)});
			ans+=gtt(x,cnt[x]);
		}
		while(B.top().val>S.top().val)
		{
			int id=B.top().id;
			ans+=B.top().val;
			cnt[id]++;
			B.erase(B.top());
			if(cnt[id]!=1)S.erase({id,get(id,cnt[id]-2)});
			B.insert({id,get(id,cnt[id])});
			S.insert({id,get(id,cnt[id]-1)});
//			cout<<B.size()<<" "<<S.size()<<" "<<B.top().val<<" "<<S.top().val<<" "<<ans<<"!!\n";
			
			id=S.top().id;
			ans-=S.top().val;
			cnt[id]--;
			S.erase(S.top());
			B.erase({id,get(id,cnt[id]+1)});
			B.insert({id,get(id,cnt[id])});
			if(cnt[id])S.insert({id,get(id,cnt[id]-1)});
			
		}
		cout<<fixed<<setprecision(6)<<ans<<"\n";
		
	}
	pc('1',1);
	return 0;
}