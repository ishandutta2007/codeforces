#abraao
x,y = map(int,raw_input().split())
parent = [0] * (x + 1)
sz = [1] * (x + 1)
dicio = {}
for i in range(1, x + 1):
  parent[i] = i
 
def find_parent(x):
  if x == parent[x]:
    return x
 
  parent[x] = find_parent(parent[x]) 
  return parent[x]
 
def union_sets(x, y):
  p_x = find_parent(x)
  p_y = find_parent(y)
 
  if p_x != p_y:
    if sz[p_x] > sz[p_y]:
      parent[p_y] = p_x
      sz[p_x] += sz[p_y]
    else:
      parent[p_x] = p_y
      sz[p_y] += sz[p_x]
    return True
  else:
    return False
 
 
lista = []
def contar(mat):
    global count
    for j in mat:
        if dicio[j-1] == False:
            dicio[j-1] = True
            count = min(count,lista[j-1])
            newcount = count
 
    return newcount
 
lista = map(int,raw_input().split())
 
for i in range(x):
    dicio[i] = False
 
 
for i in range(y):
    a,b = map(int, raw_input().split())
    union_sets(a,b)
 
mat = [[]for j in range(x+1)]
 
for i in range(1,x+1):
 
    mat[find_parent(i)].append(i)
 
newcount = 0
final = 0
 
for i in range(x+1):
    count = 100000000000000000000000000000000000
    if len(mat[i]) >= 1:
        final += contar(mat[i])
 
 
print final