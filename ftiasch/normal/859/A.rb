n = gets.to_i
puts [0, gets.split.map(&:to_i).max - n - (25 - n)].max