n = gets.to_i
need = [0]
n.times do |i|
    need << need[-1] + (n - i - 1) * (i + 1) + 1
end
puts need[n]