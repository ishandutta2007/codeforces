/*
//
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@O[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
//                                   ............=OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOooOO@@@OO`................
//                                   ...........=OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOoOO@OO^...............
//                                   ..........,oOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOO\*................
//                                   .........*oOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO@OO*...............
//                              .............*OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@O...............*/
//                              ............*/OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..............
//                                .........*oOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\..............
//                                 ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.............
//                              .. ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@O^............
//                              .. ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOooooooooOOooooooooooooOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^...........
//                              .. ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOoooooooooooooooooooooooOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..........
//                                .........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOooooooooooooooooooOOOOOO@@@@@OOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@O\....... ..
//                                .........=O@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@@@@@@@OOOOOOooooooooooooOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@O*......... .
//                                 ........=O@@@@@@@@@@@@@@@@@@@@@@OOOOOOoooooOOOOOOOOOOOoooo/*,\ooooOOOOOOOOOOOooooOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@O............
//                                 ........=O@@@@@@@@@@@@@@OOOOOOOOOOoooo^****=ooooooooooooo^****,oooOOOOOOOOO@OOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@o..........
//                              .. ........=O@@@@@@@@@OOOOOOOOOOOOoooooo^*****[oooOOOOOOoooo`*****oooOOO@@@OOoooOOO@@@@@@@@@@@@@OOOO@@@@@@@@@@@@@@@@@O`.............
//                              ...........*O@@@@@@@@OOOOOOOOOOoooooooooooOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@OOo..,OOOOOOOO@@@@@@@@@@@@@O@@@@@@@@@@@@@@@@@OO`............
//                     ......   ...........*O@@@@@@@@OOOOOOOooooooooOOOOOoo**oO@@@@@@@OOOOOOOO@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOO@@@OOOO@@@@@@@@@@@Oo*...........
//                     ......   .. .........o@@@@@@@@@OOOooooOOO@@@OOooOOOOOOOOOOOOOOOOooOOooOO@@@OoOOO@@@OOOOOOOOOOOOOOOOOOOOOOOOOO@@OOOOO@@@@@@@@@@@@O\.......
//                     ......   .. .........=@@@@@@@@@OOOO@@@@@@@@OooOOOOOOOOoooOOOOoooooooooO@@@OoooOO@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@OO^......
//                     . .       .........../O@@@@@@@@@@@@@@@@@@@@@OOOOOOoo/[[`,ooo/[[[[ooooOO@@Oo/[ooOOO@@@OOOOOOoooooooooOOOOOO@@@OOOOO@@@@@@@@@@@@@@Oo*......
//                     . .       .........*/OO@@@@@@@@@OOOOOOOOOOO@Ooooooo/**************\oooOOO*****,ooOOO@@@@OOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@Oo*.............
//                     . .         .....*/o/=ooooooOOOOOOOOoooooooOOOo[\o****************=ooOOO`*****]oOOOOOOO@@@OOOOOOOOOOooOOOOOOOOOO@@@@@@@@@@@@@@OO^........   .....
//                     . .         .....=ooO@@@OOOoo/OOOOOOooooooooOOO`**************]]/OOOOO[ooooOOOOOOO@@@OOOO@@OooooooooooOOOOOOOOOOO@@@@@@@@@@@@@OO*........   .....
//                                   ...=OOOOOOo/,ooooOOOOOOoooooooooOOOOOOOOOOOOOOOoooooooooOO@@@OOOOO@@@@@OOO@@OOoooooooooOOOOOOOOOO@@@@@@@@@@@@@@OO/..................
//                                 .....*oOoOOOoo****/OOOOOOOoooooooo\`*****[`*****,[[[[,oOOOOOOoooOOOOOOOOOOOOOOOOOooooooOOOOOOOOOOOO@@@@@@@@@@@@@@OO*..................
//                                 ......*oOoOOooooOOOOOOOOOOOooooooooo`******.....******,ooOOOoo`*,ooooooOOOOOOOOOOOOooOOOOOOOOOOOOO@@@@@@@@@@@@@@@O^...................
//                                   .....*\OOooooOOOOOoOOOOOOOooooooooooo]]]`****..*****************ooooooOOOOOOOOOOOOOOOO@OOOOOOOOO@@@@@@@@@@@@@@OO^...................
//                                   .......,OOOooOOOo`*\OOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooo\]***,oooooOOOOOOOOOOOOOO@@@@OOOOOOOOO@@@@@@@@@@@@@@OOOOOo]*..............
//                                ...........*oOOoooo\***=OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@OOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@OOO]............. .
//                                ............*OOOooooo[[oOOOOO@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\........... .
//                              ...............=O@OOOooo**oOO@@@@@OOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@OOOOOOO@@@@@OOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`...........
//                              ...............*oO@@Oo^****\O@@@@@@@OOOOOOOOOOOOOOOOO@@@@@@@@@@@@OOOOOOOOO@@@@@@@@OOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..........
//                     ....................,]oOOO@@@@Oo]]/ooOO@@@@@@@@OOOOOOOOOOOOOOO@@@@@@OOOOOOOOO@@@@@@@@@@@@@@@@@OOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`.........
//                     ...................=O@@@@@@@@@@@OOOOOOO@@@@@@@@@@@OOOOOOOOOOOO@@@@@OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@o........
//                 . ..................../O@@@@@@@@@@@@@@@Oo[[OOO@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@OOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.......
//                 ...................../O@@@@@@@@@@@@@@@@OO\`,oOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@@@@@@@^..... .
//                 ...................,O@@@@@@@@@@@@@@@@@@........OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/.........
//                 ...............=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`.........
//                 ............../O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO[`*..=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..........
//                 ............./O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOooo[ooOO@@@@@OOOOOO@OOO[........[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`..............
//                 .........../O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@@@OOOOOOO@@@@@@@@@OOOOOOOOOOOooooooo[[.............=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^...............
//                 .........,OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@OO@@@@@@@OOOO/[*.,O@OOOOOO@@@OOOOOo*.........................\O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^................
//                 ........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@OO@@@@@OOOO[*.....OOOOooO@@@OOoooo`...........................O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^.................
//                 .......=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@OO@@@@@OO/`.........\OOOOooO@@Oooo/*............................,OO@@@@@@@@@@@@@@@@@@@@@@@@@@/..................
//                 ......,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOO@OO@@@@OO[..............,oOOOO@@O/`*...............................,O@@@@@@@@@@@@@@@@@@@@@@@@@O..................
//               ........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOO@@@O`....................,oOOO*...................    ...........=O@@@@@@@@@@@@@@@@@@@@@@@O^...................
//               ........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@@/.................................................... ..........=O@@@@@@@@@@@@@@@@@@@@@@O....................
//                .......=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOO@@@@O..................................................... ...........\O@@@@@@@@@@@@@@@@@@@@O^....................
//          ...    .....,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..................................................................O@@@@@@@@@@@@@@@@@@@@O*....................
//        ......   .....O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO^..................................................................=O@@@@@@@@@@@@@@@@@@@^.....................
//        ... ... ......=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O/................***.................................................oO@@@@@@@@@@@@@@@@@O^.....................
//            .. ........\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Oo*...........*,oOOOOOOOOOOOOOOOOOOOOOOOOOOOOo]].............*]]]]*....,O@@@@@@@@@@@@@@@@@@^...................
//            .. .........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.........*/OOOO@@OOOOOOOOOOOOOOOOOO@@OOOOOOOOOOO@@@@@@@@@@@@@@@O^.....\O@@@@@@@@@@@@@@@@@^...................
//          .....  ........,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O*........*/oOOOOOOOOOOOOOOOOOOOOOOOOOOo[[[[[[[[[[[[[\o//[[[\OO@@@o.....,O@@@@@@@@@@@@@@@@O^.....................
//                 ..........O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Oo*.......*oOOO^..............................................,O@@@O*.....O@@@@@@@@@@@@@@@@O`.....................
//                 ..........O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO`.........*\OO\............   ......   .......................oO@@O......\O@@@@@@@@@@@@@@@O^..........=OOOO].......
//               ............O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Oo*...........oOo`..............................................=O@Oo......=O@@@@@@@@@@@@@@@O^.............,\OOO......
//               .............\O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^............\OOO........... ..............  ..................*O@@O......=O@@@@@@@@@@@@@@@O^................\OO*. ..
//                 ............=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^............=O@@o...........   .....   .......................=O@@O*......O@@@@@@@@@@@@@@@@^......=O@OO\.....\@O.....
//                 .............,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^............=O@@O^.........    .....    ......................=O@@O*......O@@@@@@@@@@@@@@@@^.........,\O/....=OO\....
//                 ..............,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.............o@@O\.........            .......................=O@O\.......OO@@@@@@@@@@@@@@@O..................,[`....
//                 ...............,O@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..............\O@O^........             .....................=O@@O/......*O@@@@@@@@@@@@@@@@@\........................
//                 .................\O@@@@@@@@@@@OOO@@@@@@@@@@@O^................\OO`...........       ....       ............=@@O/.......*O@@@@@@@O/...,[\O@O\..............  .......
//                  ..................\O@@@@@@O`...=O@@@@@@@@@@O^.................=OO\........  ..  .......       ............O@@O^.......,O@@@@@@@Oo......*OOO^.........
//                     .  ..............O@@@@/.....,O@@@@@@@@@@O^..................*oOO\.....................................=O@@O*......,OO@@@@@@O/`.......=OOO.........
//                      ................O@O^.......O@@@@@@@@@@@Oo**..................*\OOO\................................*O@@@@O\]OOOOOO@@@@@@@O^.......*/O@OO.........
//                 .....................OO^........=@@@@@@@@@@@OOOOoooooOOOOOOOOOOOo\/oOOOOO\]]]]]*****................*]oO@@@@@@@@@@@@@@@@@@@@@@@O...*/OO@@@@O`.........
//                 .....................OO^.......*/O@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@@OOO\]]]]]/OOO@@@@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@/........
//                 .....................oO\.......=O@@@@@@@@@@@@@@@OOOO/[[`**.*..***...***[[[[[\oOOOOOOOOO@@@@@@@@@@@@@@@@@@@@OOOO/[[[[oooOO@@@@@@@@@@@@@@O[.....  .
//                 ......................OO@O\....=O@@@@@@@@@@@@@@@O/****..........................***,\o/[**,[[[`*,[[[[[[[[***...******`oOO@@@@@@@@@@@@@O^.......
//               ........,....,\*.........\@@@O\]]/@@@@@@@@@@@@@@@@@O^*................................*=oo]*........................***ooO@@@@@@@@@@@@@@O*.......
//                 ......O\....,O^..........\O@@@@@@@@@@@@@@@@@@@@@@Oo**...............................*oOOO`........................*.*]OO@@@@@@@@@@@@@O^......
//                 ......=O^.....\o...........,[O@@@@@@@@@@@@@@@@@@@@O^**..............................=OOOO^......................,]/OO@@@@@@@@@@@@@@@@O\........
//                 ........O\....................,O@@@@@@@@@@@@@@@@@@@Oo`*****.........................*\OO/*.................**]OOOO@@@@@@@@@@@@@@@@@@@@@O^....
//               ...........,`................../O@@@@@@@@@@@@@@@@@@@@@@@OOOo\]]*********...............****.*............**]OOO@@@@@@@@@@@@@@@@@@@@@@@@@OOO.....
//               ..............................*O@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOo\]]]]]**************,]/oOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^........
//                 ..         .....  ........,OO@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O.........
//                                   .......,OOO@@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOO@O@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@OOOOOOOOOO@@O`.........
//                               ............O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOO@@@O......
//                               ...........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@OOOOOO@@@@O`....
//                              .. ........*O@@@OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@OOOO@@@@@@O^.....
//                              .. ........=O@@@OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O........
//                              .. ........=O@@@OOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O/...    .
//                                 ...........,.......................................................**...................................................
//                                   ................................................................/@^....O@@@@@^........................................
//                                     ...  ..                             ...                    .@/[[[\@^.@@...@^....
//                                                                                                .@^=@.=@^,@^...@O....
//                                                                                              ...@^.\/=@^O/....,[[[..
//                                                                         .@@@@@@@@@@@@@@@@@@@O.=@@@@@@@@^@@@@@@@@@...
//                                                                                                .@^,`.=@^,@\...,@^.
//                                                                                                =@^.@\=@^.,@\.,@/..
//                                                                                             .../@....=@^...O@@^...
//                                                                                             ..,@/..]]/@^]@@@[[@@@]..
// ...                                                                                         ...`...,[`..............

#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,siz[N],tot;
ll ans[N],mx;
vector<int> A;
vector<pair<int,int> > G[N];
struct Link{
	int x,y,id;
}L[N];
map<int,vector<Link> > mp;
struct Union_Set{
	int f[N],s[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i,s[i]=1;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		f[fy]=fx;
		s[fx]+=s[fy];
	}
}S;
void dfs1(int u,int fa){
	siz[u]=S.s[u];
	for(auto [v,id]:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];	
	}
}
void dfs2(int u,int fa){
	for(auto [v,id]:G[u]){
		if(v==fa)continue;
		dfs2(v,u);
		ans[id]=1LL*siz[v]*(tot-siz[v]);	
	}	
}
int main(){
	n=read();
	S.init(n);
	for(int i=1;i<n;++i){
		L[i].x=read(),L[i].y=read();
		int w=read();
		L[i].id=i;
		mp[w].push_back(L[i]);
	}
	for(auto [w,vec]:mp){
		for(auto t:vec){
			int fx=S.getf(t.x),fy=S.getf(t.y);
			G[fx].emplace_back(fy,t.id);
			G[fy].emplace_back(fx,t.id);
		}
		for(auto t:vec){
			int fx=S.getf(t.x);
			if(!siz[fx]){
				dfs1(fx,0);
				tot=siz[fx];
				dfs2(fx,0);
			}
		}
		for(auto t:vec){
			int fx=S.getf(t.x),fy=S.getf(t.y);
			G[fx].clear();
			G[fy].clear();
			siz[fx]=siz[fy]=0;
		}
		for(auto t:vec){
			S.Merge(t.x,t.y);
		}
	}
	for(int i=1;i<n;++i)mx=max(mx,ans[i]);
	for(int i=1;i<n;++i)if(mx==ans[i])A.push_back(i);
	printf("%lld %d\n",2*mx,(int)A.size());
	for(auto x:A)printf("%d ",x);
	return 0;
}