#include<bits/stdc++.h>

#define in(n) fscanf(input, "%d",&(n))
#define out(n) fprintf(output, "%d",(n))
#define inl(n) fscanf(input, "%lld",&(n))
#define outl(n) fprintf(output, "%lld",(n))
#define SP fprintf(output, " ")
#define NL fprintf(output, "\n")
#define MP make_pair
#define PB push_back

#define FOR(i,n) for(i=0;i<n;i++)
#define FOR1(i,n) for(i=1;i<=n;i++)
#define ff first
#define ss second
#define debug(a) cout<<#a<<" --> "<<a<<endl;
#define debug1(a) cout<<#a<<" --> "<<a<<" ";

#define spurt(i) {if(i==0) cout<<"A"; else if(i==1) cout<<"B"; else cout<<"C";}

using namespace std;

typedef long long ll;

int test_no;
int i;
vector<pair<int,int> > dim(3,make_pair(0,0));


/*Code I changed*/
int x, y, z;

int do_that()
{
            if(dim[z].ff==dim[x].ff && (dim[x].ff==(dim[x].ss+dim[y].ss+dim[z].ss))){

                cout<<dim[x].ff<<endl;

                for(int i=0;i<dim[x].ss;i++){
                    for(int j=0;j<dim[x].ff;j++)
                        spurt(x)
                    cout<<endl;
                }

                for(int i=0;i<dim[y].ss;i++){
                    for(int j=0;j<dim[y].ff;j++)
                        spurt(y)
                    cout<<endl;
                }

                for(int i=0;i<dim[z].ss;i++){
                    for(int j=0;j<dim[z].ff;j++)
                        spurt(z)
                    cout<<endl;
                }

                return 0;
            }
            if(dim[z].ss==(dim[x].ss+dim[y].ss) && dim[z].ss==(dim[z].ff+dim[x].ff)){

                cout<<dim[z].ss<<endl;

                for(int i=0;i<dim[x].ss;i++){

                    for(int j=0;j<dim[x].ff;j++)
                        spurt(x)
                    for(int j=0;j<dim[z].ff;j++)
                        spurt(z)
                    cout<<endl;
                }

                for(int i=0;i<dim[y].ss;i++){

                    for(int j=0;j<dim[y].ff;j++)
                        spurt(y)
                    for(int j=0;j<dim[z].ff;j++)
                        spurt(z)
                    cout<<endl;
                }

                return 0;
            }
    return -1;
}
/*End of code I change*/

int main() {

    FOR(i,3){

        cin>>dim[i].ff;
        cin>>dim[i].ss;
    }


for(int test=0;test<8;test++){

    if(dim[0].ff==dim[1].ff || dim[2].ff==dim[1].ff || dim[0].ff==dim[2].ff){

        if(dim[0].ff == dim[1].ff){

            x=0,y=1,z=2;
            if (do_that() == 0) return 0;

        }
        if(dim[1].ff == dim[2].ff){

            x=1,y=2,z=0;
            if (do_that() == 0) return 0;

        }
        if(dim[0].ff == dim[2].ff)
        {

            x=2,y=0,z=1;
            if (do_that() == 0) return 0;

        }
        //All code from here was moved to do_that()

    }

    switch(test){

        case 0:swap(dim[0].ff,dim[0].ss);break;
        case 1:swap(dim[1].ff,dim[1].ss);break;
        case 2:swap(dim[0].ff,dim[0].ss);break;
        case 3:swap(dim[2].ff,dim[2].ss);break;
        case 4:swap(dim[1].ff,dim[1].ss);break;
        case 5:swap(dim[0].ff,dim[0].ss);break;
        case 6:swap(dim[1].ff,dim[1].ss);break;

    }

}

    cout<<-1<<endl;

    return 0;


}