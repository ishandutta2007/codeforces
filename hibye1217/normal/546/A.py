k, n, w = map( int, input().split() )
need = k*w*(w+1) // 2
print( max(need-n, 0) )