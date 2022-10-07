#include<stdio.h>
int n,m;
int en[400100];
int el[400200];
int ep[400200];
int dn[400100];
int ds[400100][2];
int dd[400100][2];
int q[400100];
int left[400100];
int qs,qe;
int fix[400100];
int val[400100];
int sat[400100];
int main(){
	int i,j,k,p,c;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		left[i]=k;
		en[i+1]=en[i]+k;
		for(j=en[i];j<en[i+1];j++){
			scanf("%d",&el[j]);
			if(el[j]>0){
				ep[j]=1;
				dd[el[j]][dn[el[j]]]=1;//plus -> 1 minus -> 0
				ds[el[j]][dn[el[j]]]=i;
				dn[el[j]]++;
			}
			else{
				ep[j]=0;
				el[j]=-el[j];
				ds[el[j]][dn[el[j]]]=i;
				dn[el[j]]++;
			}
		}
	}
	qs=qe=0;
	for(i=1;i<=m;i++){
		if(dn[i]!=2||dd[i][0]==dd[i][1]){
			val[i]=dd[i][0];
			fix[i]=1;
			q[qe]=i;
			qe++;
		}
	}
	for(i=0;i<n;i++){
		if(en[i+1]-en[i]==1){
			if(fix[el[en[i]]]==1){
				if(val[el[en[i]]]!=ep[en[i]]){
					printf("NO");
					return 0;
				}
			}
			else{
				val[el[en[i]]]=ep[en[i]];
				fix[el[en[i]]]=1;
				q[qe]=el[en[i]];
				qe++;
			}
		}
	}
	while(qs<qe){
		p=q[qs];
		for(j=0;j<dn[p];j++){
			c=ds[p][j];
			if(val[p]==dd[p][j]){
				if(sat[c]==0){
					sat[c]=1;
					for(k=en[c];k<en[c+1];k++){
						if(fix[el[k]]!=1){
							val[el[k]]=!ep[k];
							fix[el[k]]=1;
							q[qe]=el[k];
							qe++;
						}
					}
				}
			}
			else{
				if(sat[c]==0){
					left[c]--;
					if(left[c]<=1){
						for(k=en[c];k<en[c+1];k++){
							if(fix[el[k]]==1){
								if(val[el[k]]==ep[k]){
									sat[c]=1;
									break;
								}
							}
						}
						if(sat[c]==0){
							for(k=en[c];k<en[c+1];k++){
								if(fix[el[k]]!=1){
									val[el[k]]=ep[k];
									fix[el[k]]=1;
									q[qe]=el[k];
									qe++;
									sat[c]=1;
									break;
								}
							}
						}
						if(sat[c]==0){
							printf("NO");
							return 0;
						}
					}
					if(sat[c]==1){
						for(k=en[c];k<en[c+1];k++){
							if(fix[el[k]]!=1){
								val[el[k]]=!ep[k];
								fix[el[k]]=1;
								q[qe]=el[k];
								qe++;
							}
						}
					}
				}
			}
		}
		qs++;
	}
	for(i=1;i<=m;i++){
		if(fix[i]==0){
			fix[i]=1;
			q[qe]=i;
			qe++;
			while(qs<qe){
				p=q[qs];
				for(j=0;j<dn[p];j++){
					c=ds[p][j];
					if(val[p]==dd[p][j]){
						if(sat[c]==0){
							sat[c]=1;
							for(k=en[c];k<en[c+1];k++){
								if(fix[el[k]]!=1){
									val[el[k]]=!ep[k];
									fix[el[k]]=1;
									q[qe]=el[k];
									qe++;
								}
							}
						}
					}
					else{
						if(sat[c]==0){
							left[c]--;
							if(left[c]<=1){
								for(k=en[c];k<en[c+1];k++){
									if(fix[el[k]]==1){
										if(val[el[k]]==ep[k]){
											sat[c]=1;
											break;
										}
									}
								}
								if(sat[c]==0){
									for(k=en[c];k<en[c+1];k++){
										if(fix[el[k]]!=1){
											val[el[k]]=ep[k];
											fix[el[k]]=1;
											q[qe]=el[k];
											qe++;
											sat[c]=1;
											break;
										}
									}
								}
								if(sat[c]==0){
									printf("NO");
									return 0;
								}
							}
							if(sat[c]==1){
								for(k=en[c];k<en[c+1];k++){
									if(fix[el[k]]!=1){
										val[el[k]]=!ep[k];
										fix[el[k]]=1;
										q[qe]=el[k];
										qe++;
									}
								}
							}
						}
					}
				}
				qs++;
			}
		}
	}
	puts("YES");
	for(i=1;i<=m;i++){
		printf("%d",val[i]);
	}
}