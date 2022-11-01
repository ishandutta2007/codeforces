/*
* photograph.c
* 
        
		 
         
*  3180102689
* 2018/11/21 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define N 605
#define maxVex 20

int h, w, t;
double pix[N][N];
double tmp[N][N];	

struct Graph
{
	int vexNum;//
	double dis[maxVex][maxVex];// 
};
struct Graph idGraph; 

struct TSPsolution
{
	int vexNum;// 
	double len;// 
	int path[maxVex];// 
};
struct TSPsolution idTSPsolution;


/*
* max
* 
*/
int max(int a, int b) 
{
	return a > b ? a : b;
}

/*
* min
* 
*/
int min(int a, int b)
{
	return a > b ? b : a;
}
 

/*
* init
* pix 
*/
void init() 
{
	memset(pix, 0, sizeof(pix));
	memset(tmp, 0, sizeof(tmp));
	scanf("%d%d%d", &h, &w, &t);
	
	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++)
			scanf("%lf", &pix[i][j]);
	
	return ;
}

/*
* CreateGraph
* 
* Graph 
* 1int min(int a, int b)
* 2int max(int a, int b) 
*/
struct Graph CreateGraph() 
{
	struct Graph ret = idGraph;

	//tmp[i][j](i,j) 
	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++) 
		{
			//(i,j) 
			int cnt = 0;
			//(i,j) 
			int num = (i-1) / (h/t);
			
			//(i,j) 
			int up = max(num*h/t+1, i-1);
			int down = min((num+1)*h/t, i+1);
			int left = max(1, j-1);
			int right = min(w, j+1);
	
			
			for (int p=up;p<=down;p++)
				for (int q=left;q<=right;q++)
				{
					tmp[i][j] += pix[p][q];
					++cnt;
				}
			tmp[i][j] /= cnt;
			
		}


	// 
	ret.vexNum = t;
	for (int i=0;i<t;i++)
	{
		for (int j=0;j<t;j++)
		{
			double sum = 0;
			int div = 10;
			for (int k=0;k<w/div;k++) {
				double s1 = 0, s2 = 0;
				for (int u = k * div+1; u <= (k + 1)*div; u++)
				{
					int x = (i + 1) * (h / t);
					int y = j * (h / t) + 1;
					s1 += tmp[x][u];
					s2 += tmp[y][u];
				}
				sum += abs(s1 - s2);
			}
			ret.dis[i][j] = sum;
		}

	}
	
	return ret;
}

/*
* TSPcalclen
* TSP
* 1x *TSPsolution TSP
* 2G *Graph TSP 
* double TSP 
*/
double TSPcalclen(struct TSPsolution *x, struct Graph *G) 
{
	double sum = 0;
	int n = x->vexNum; 
	for (int i=1;i<n;i++)
	{
		int u = x->path[i];
		int v = x->path[i+1];
		sum += G->dis[u][v];
	}
	return sum;
}


/*
* TSPswap
* TSP 
* 1x TSPsolution TSP 
* 2i 1 
* 3j 2 
*/
void TSPswap(struct TSPsolution *x, int i, int j) 
{
	int t;
	t = x->path[i];
	x->path[i] = x->path[j];
	x->path[j] = t;
	return ;
}


/*
* TSProtate
* TSP 
* 1x *TSPsolution 
* 2l int
* 3r int 
*/
void TSProtate(struct TSPsolution *x, int l, int r) 
{
	if (l > r)
	{
		int t;
		t = l;
		l = r;
		r = t;	
	}
	
	int tmp = x->path[r];
	for (int i=r;i>l;i--)
		x->path[i] = x->path[i-1];
	x->path[l] = tmp;
	return ;
}

/*
* TSPshift
* TSP 
* 1x *TSPsolution 
* 2l int
* 3r int 
*/
void TSPshift(struct TSPsolution *x, int l, int r) {
	int a[20], tot = 0, n = x->vexNum;
	for (int i=l;i<=r;i++) a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++)
		if (i>r)
			a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++)
		if (i<l)
			a[++tot] = x->path[i];
			
	for (int i=1;i<=n;i++) x->path[i] = a[i];
} 

/*
* TSPlsh
* TSP[1,l-1][l,r-1] 
* 1x *TSPsolution 
* 2l int
* 3r int 
*/
void TSPlsh(struct TSPsolution *x, int l, int r) 
{
	int a[20], tot = 0, n = x->vexNum;
	for (int i=l;i<=r;i++) a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++)
		if (i<l || i > r)
			a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++) x->path[i] = a[i];
} 

/*
* TSPrsh
* TSP[l,r-1][r,n] 
* 1x *TSPsolution 
* 2l int
* 3r int 
*/
void TSPrsh(struct TSPsolution *x, int l, int r) 
{
	int a[20], tot = 0, n = x->vexNum;
	
	for (int i=1;i<=n;i++)
		if (i<l || i > r)
			a[++tot] = x->path[i];
			
	for (int i=l;i<=r;i++) a[++tot] = x->path[i];
			
	for (int i=1;i<=n;i++) x->path[i] = a[i];
} 


/*
* SA_TSP
* TSP 
* 1G Graph
* 2bestSol TSPsolutionTSP 
* TSPsolutionTSP 
* 1TSPswap(struct TSPsolution *x, int i, int j) 
* 2TSPshift(struct TSPsolution *x, int l, int r)
* 3TSProtate(struct TSPsolution *x, int l, int r) 
* 4TSPrsh(struct TSPsolution *x, int l, int r)
* 5TSPrsh(struct TSPsolution *x, int l, int r)
* 6TSPcalclen(struct TSPsolution *x, struct Graph *G) 
*/ 
struct TSPsolution NewSolution(struct Graph *G, struct TSPsolution bestSol) 
{
	struct TSPsolution ret = idTSPsolution;
	
	int i = rand() % G->vexNum + 1;
	int j = rand() % G->vexNum + 1;
	
	if (i > j) 
	{
		int t;
		t = i;
		i = j;
		j = t;
	}
	
	if (i == j) 
	{
		ret = bestSol;
		return ret;	
	}
	
	// 
	int cmd = rand() % 5; 
	if (cmd == 0) 
	{
		// 
		TSPswap(&bestSol, i, j); 
		bestSol.len = TSPcalclen(&bestSol, G);
	}
	
	if (cmd == 1) 
	{
		// 
		if (j == G->vexNum)// 
		{
			ret = bestSol;
			return ret;
		}
		TSProtate(&bestSol, i, j);
		bestSol.len = TSPcalclen(&bestSol, G);
	}
	
	if (cmd == 2) 
	{
		//[1,i-1][i,n] 
		if (i == 1) // 
		{
			ret = bestSol;
			return ret;
		}
		TSPshift(&bestSol, i, j);
		bestSol.len = TSPcalclen(&bestSol, G);
	}
	
	if (cmd == 3) 
	{
		//[1,i-1][i,j-1] 
		if (i == 1) 
		{
			ret = bestSol;
			return ret;
		}
		TSPlsh(&bestSol, i, j);
		bestSol.len = TSPcalclen(&bestSol, G);
	}
	
	if (cmd == 4) 
	{
		//[i,j-1][j,n] 
		if (i == 1)
		{
			ret = bestSol;
			return ret;
		}
		TSPrsh(&bestSol, i, j);
		bestSol.len = TSPcalclen(&bestSol, G);
	}
	
	ret = bestSol;
	return ret;
}


/*
* RandomSolution
* TSP 
* 1n int 
* 2G *Graph
* TSPsolutionTSP
* 1NewSolution 
*/
struct TSPsolution RandomSolution(int n, struct Graph *G) {
	int a[20], b[20];
	struct TSPsolution ret = idTSPsolution;
	
	for (int i=1;i<=n;i++) a[i] = i;
	for (int i=1;i<=n;i++) b[i] = rand();
	
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (b[ a[i] ] > b[ a[j] ])
			{
				int tmp;
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
	
	ret.vexNum = n;
	
	for (int i=1;i<=n;i++)
		ret.path[i] = a[i] - 1;
	
	ret.len = TSPcalclen(&ret, G);
	
	return ret;	
}

/*
* SA_TSP
* TSP 
* 1G Graph
* TSPsolutionTSP
* 1NewSolution 
*/ 
struct TSPsolution SA_TSP(struct Graph G) 
{
	const double speed = 0.998;// 
	const double initTem = 1e9;//
	const double minTem = 0.000001;//
	const int T = 1;// 

	
	int n = G.vexNum;
	struct TSPsolution bestSol = idTSPsolution;// 
	struct TSPsolution curSol = idTSPsolution;// 

	// 
	bestSol = RandomSolution(n, &G);
	
	double curTem = initTem;
		
	while (curTem > minTem) 
	{
		for (int i=1;i<=T;i++) //
		{
			curSol = NewSolution(&G, bestSol);//
			if (curSol.len <= bestSol.len) 
			{
				bestSol = curSol;	
			} 
			else
			{
				//Metropolis
				double diff = bestSol.len - curSol.len;
				int t1 = rand() % RAND_MAX;
				int t2 = RAND_MAX;
				double r = (double)t1 / (double)t2; //0-1
				double x = exp(diff / curTem);
				
				if (x > r)
				{
					bestSol = curSol;
				}

			}
		} 
		curTem = curTem * speed; //speed 
	} 
		
	return bestSol;
}

/*
* print
* TSP 
* 1ans TSPsolutionTSP 
*/ 
void print(struct TSPsolution ans) 
{
	
	int res[N];
	
	for (int i=1;i<=ans.vexNum;i++)
		res[ ans.path[i]+1 ] = i;
	
	for (int i=1;i<=ans.vexNum;i++)
		printf("%d%c", res[i], i==ans.vexNum ? '\n' : ' ');
	return ;
}

/*
* solve
* 
* 1init()
* 2CreateGraph()
* 3struct TSPsolution SA_TSP(struct Graph G)  
*/
void solve() 
{
	struct Graph G;
	struct TSPsolution ans;

	init();// 
	
	G = CreateGraph();//
	 
	ans = SA_TSP(G);// 
	print(ans);// 

	return ;
}

/*
* main
* main 
*/
int main() 
{
//	freopen("photograph.in","r",stdin);
//	freopen("photograph.out","w",stdout);
	
	srand(0);
	
	int T = 0;
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
		
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}