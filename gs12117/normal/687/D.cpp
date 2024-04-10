#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
int n,m,q;
int uft[1010][2];
int uftf(int x){
	if(x==uft[x][0])return x;
	uftf(uft[x][0]);
	uft[x][1]=uft[uft[x][0]][1]^uft[x][1];
	uft[x][0]=uft[uft[x][0]][0];
	return uft[x][0];
}
struct edge{
	int a,b,c;
	bool operator<(const edge&r)const{
		return c>r.c;
	}
};
struct edgeb{
	int a,b,c;
	bool operator<(const edgeb&r)const{
		return c<r.c;
	}
};
edge eg[501000];
struct itnod{
	std::vector<edge> *a;
	itnod operator+(itnod z){
		itnod res;
		res.a=new std::vector<edge>;
		int i,j;
		edge t;
		for(i=1;i<=n;i++){
			uft[i][0]=i;
			uft[i][1]=0;
		}
		i=0;
		j=0;
		while(i<a->size()||j<z.a->size()){
			if(i!=a->size()&&(j==z.a->size()||(*(a))[i]<(*(z.a))[j])){
				t=(*a)[i];
				i++;
			}
			else{
				t=(*z.a)[j];
				j++;
			}
			if(uftf(t.a)!=uftf(t.b)){
				uft[uft[t.a][0]][1]=1^uft[t.a][1]^uft[t.b][1];
				uft[uft[t.a][0]][0]=uftf(t.b);
				(*res.a).push_back(t);
			}
			else{
				if(uft[t.a][1]==uft[t.b][1]){
					(*res.a).push_back(t);
					break;
				}
			}
		}
		return res;
	}
};
const int bucketsz=1<<0;
const int itsz=1<<19;
itnod it[2*itsz];
edge es[itsz][bucketsz];
int essz[itsz];
std::priority_queue<edgeb> pq;
itnod itcalc(int start,int end){
	start+=itsz;
	end+=itsz;
	itnod res;
	res.a=new std::vector<edge>;
	std::vector<edge>* pa=res.a;
	while(start<=end){
		if(start%2==1){
			res=res+it[start];
			pa->clear();
			pa->shrink_to_fit();
			free(pa);
			pa=res.a;
			start++;
		}
		if(end%2==0){
			res=res+it[end];
			pa->clear();
			pa->shrink_to_fit();
			free(pa);
			pa=res.a;
			end--;
		}
		start/=2;
		end/=2;
	}
	return res;
}
int main(){
	int i,j,k;
	int a,b;
	edgeb t;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&eg[i].a,&eg[i].b,&eg[i].c);
	}
	for(i=0;i<m;i++){
		es[i/bucketsz][essz[i/bucketsz]]=eg[i];
		essz[i/bucketsz]++;
	}
	for(i=0;i<itsz;i++){
		std::sort(es[i],es[i]+essz[i]);
	}
	for(i=itsz;i<2*itsz;i++){
		it[i].a=new std::vector<edge>;
		for(j=0;j<essz[i-itsz];j++){
			it[i].a->push_back(es[i-itsz][j]);
		}
		it[i].a->shrink_to_fit();
	}
	for(i=itsz-1;i>0;i--){
		it[i]=it[i*2]+it[i*2+1];
		it[i].a->shrink_to_fit();
	}
	for(k=0;k<q;k++){
		scanf("%d%d",&a,&b);
		a--;
		b--;
		itnod s=itcalc(a/bucketsz+1,b/bucketsz-1);
		edge ta;
		edgeb tb;
		for(i=0;i<s.a->size();i++){
			ta=(*s.a)[i];
			tb.a=ta.a;
			tb.b=ta.b;
			tb.c=ta.c;
			pq.push(tb);
		}
		for(i=a;i<=b&&i/bucketsz==a/bucketsz;i++){
			ta=eg[i];
			tb.a=ta.a;
			tb.b=ta.b;
			tb.c=ta.c;
			pq.push(tb);
		}
		if(i!=b+1){
			for(i=b;i/bucketsz==b/bucketsz;i--){
				ta=eg[i];
				tb.a=ta.a;
				tb.b=ta.b;
				tb.c=ta.c;
				pq.push(tb);
			}
		}
		for(i=1;i<=n;i++){
			uft[i][0]=i;
			uft[i][1]=0;
		}
		int ans=-1;
		while(pq.size()>0){
			t=pq.top();
			pq.pop();
			if(uftf(t.a)!=uftf(t.b)){
				uft[uft[t.a][0]][1]=1^uft[t.a][1]^uft[t.b][1];
				uft[uft[t.a][0]][0]=uftf(t.b);
			}
			else{
				if(uft[t.a][1]==uft[t.b][1]){
					ans=t.c;
					break;
				}
			}
		}
		while(pq.size()>0){
			pq.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}