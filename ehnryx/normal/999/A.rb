n,k = readline.split.map(&:to_i)
a = readline.split.map(&:to_i)

ans=0
i=0
while i<n and a[i]<=k
	ans += 1
	i += 1
end
i=n-1
while i>=0 and a[i]<=k
	ans += 1
	i -= 1
end

puts [ans,n].min